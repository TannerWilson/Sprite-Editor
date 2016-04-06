#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include <string>
#include <QPushButton>
#include <QDebug>
#include <QInputDialog>
using namespace std;

/*
* Constructor for the main form
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->update();
    ui->menuBar->activateWindow();

    screenHeight = 1000;
    screenWidth = 1000;


    // Set up stuff for the part of the GUI that allows you to add image frames,
    // browse image frames, etc.
    framesLayout = new QVBoxLayout(ui->frameContents);
    framesLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    // Set up box layout for graphics frame
    graphicsLayout = new QVBoxLayout;
    ui->graphicsframe->setLayout(graphicslayout);

    // Set the primary and secondary color choices
    ui->primaryColorButton->setStyleSheet("background-color: black");
    ui->secondaryColorButton->setStyleSheet("background-color: white");


    // set up screen width and height
    while(true)
    {
        screenHeight = QInputDialog::getInt(0, "Select Height","Input the desired height of your sprite", 1) * 25;

        if(screenHeight < 25 || screenHeight > 51200)
        {
            QMessageBox::information(
                this,
                tr("Error"),
                tr("Please input a value from 1 to 2048") );
        }
        else break;
    }

    while(true)
    {
        screenWidth = QInputDialog::getInt(0, "Select Width","Input the desired width of your sprite", 1) * 25;

        if(screenWidth < 25 || screenWidth > 51200)
       {
            QMessageBox::information(
                this,
                tr("Error"),
                tr("Please input a value from 1 to 2048") );
        }
        else break;
    }


    // Set up graphics scene for drawing
    scene = new QGraphicsScene(this);
    // Create model and pass scene pointer so it can draw to the screen.
    model = new Model(scene,screenHeight,screenWidth,25);

    // TODO Joey Set up what scene size based off image size.
    scene->setSceneRect(0,0,screenHeight,screenWidth);

    // Create graphics view
    spriteGraphicsView = new SpriteGraphicsView();
    spriteGraphicsView->setScene(scene);
    spriteGraphicsView->setFixedSize(700, 700);
    spriteGraphicsView->show();
    // Enable Mouse Events
    spriteGraphicsView->setMouseTracking(true);

    // Connect mouse signals and slots
    connect (spriteGraphicsView, SIGNAL(MouseMoveSignal(QPointF)),model, SLOT(MouseMove(QPointF)));
    connect(spriteGraphicsView, SIGNAL(MousePressSignal(QPointF)), model, SLOT(MousePressed(QPointF)));
    connect(spriteGraphicsView, SIGNAL(MouseReleaseSignal(QPointF)), model, SLOT(MouseReleased(QPointF)));

    connect(ui->StartPreview, SIGNAL(pressed()),model,SLOT(StartPreview()));
    connect(ui->StopPreview, SIGNAL(pressed()),model,SLOT(StopPreview()));

    // Add the spritegraphicsview to the layout
    graphicsLayout->addWidget(spriteGraphicsView);
    graphicsLayout->addStretch(1);

    // Initialize GUI frames window with 1 frame
    onAddFrameButtonClicked();
    model->SetCurrentImageIndex(0);


    GIFExport gifExport;

    // Connect menu bar actions
    connect(ui->actionSave, SIGNAL(triggered()), model, SLOT(Save()));
    connect(ui->actionOpen, SIGNAL(triggered()), model, SLOT(Open()));

    // pen is default tool
    onBrushButtonClicked();
    this->ui->eraserButton->setStyleSheet("border:0; background-color:none");
    this->ui->bucketButton->setStyleSheet("border:0; background-color:none");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Creates a new, blank image frame for the Sprite, shown on the left of the GUI.
 */
void MainWindow::onAddFrameButtonClicked()
{
    QPushButton *frameButton = new QPushButton(this);
    frameButton->setGeometry(0,0,individualFrameWidth,individualFrameHeight);
    QFont font("Helvetica",24);
    frameButton->setFont(font);
    QString buttonNum = QString::number(frameWidgets.size()+1);
    frameButton->setText(buttonNum);
    frameButton->setStyleSheet("background-color: white");
    framesLayout->addWidget(frameButton);
    frameWidgets.push_back(frameButton);
    connect(frameButton, SIGNAL(clicked()), this, SLOT(onFrameButtonClicked()));

    model->AddImage();
}


/*
 * Shows the selected frame on the canvas for modification
 */
void MainWindow::onFrameButtonClicked()
{
    // Get rid of border on previously selected frame button
        // Add a border to the newly selected frame button
        list<QPushButton*>::iterator it;
        it = frameWidgets.begin();
        int frameSelected = -1;
        QObject *frameButtonObj = QObject::sender(); // the button that was clicked
        QWidget *frameButton = qobject_cast<QWidget *>(frameButtonObj);
        for(size_t i= 0; i < frameWidgets.size(); i++)
        {
            QPushButton *button = *it;
            if((unsigned long)button == (unsigned long)frameButton)
            {
                frameSelected = i;
                button->setStyleSheet("background-color: white; border-color: black; border-style: solid; border-width: 3px");
            }

            else
            {
                button->setStyleSheet("background-color:white");
            }

            advance(it,1);
        }

        //qDebug() << QString::number(frameSelected);

        //Update model's current Image
        model->SetCurrentImageIndex(frameSelected);
}

/*
 * Removes the selected frame from the Sprite.
 */
void MainWindow::onDeleteFrameButtonClicked()
{
    if(frameWidgets.size() > 1)
        {
            // Remove frame from GUI
            list<QPushButton*>::iterator it;
            it = frameWidgets.begin();
            advance (it, model->GetCurrentImageIndex());
            frameWidgets.erase(it);
            QWidget *frame = *it;
            layout()->removeWidget(frame);
            delete frame;

            // Remove frame from model
            model->RemoveImageAt(model->GetCurrentImageIndex());


            // Update frame button labels and put focus on the frame that came
            // before the deleted frame
            it = frameWidgets.begin();
            for(size_t i = 0; i < frameWidgets.size(); i++)
            {
                QPushButton *button = *it;
                button->setText(QString::number(i+1));
                if(i == model->GetCurrentImageIndex())
                    button->animateClick();

                advance(it,1);
            }

        }
}

/*
 * Opens the color picker, saves the selected color, and updates the primary and secondary
 * color choices
 */
void MainWindow::onPrimaryColorButtonClicked()
{
    // First three params are meaningless... just default. Last param enables transparency option
    QColor chosenColor = QColorDialog::getColor(Qt::white, 0, QString(), QColorDialog::ShowAlphaChannel);

    // If user selected a color instead of clicking 'cancel'
    if(chosenColor.isValid())
    {
        QString styleInfo = (ui->primaryColorButton->styleSheet());

        // I don't think this is how the ux should work - GC
        //ui->secondaryColorButton->setStyleSheet(ui->primaryColorButton->styleSheet());

        QString rgbaString = QString("%1, %2, %3, %4").arg(chosenColor.red()).arg(chosenColor.green()).arg(chosenColor.blue()).arg(chosenColor.alpha());
        qDebug() << rgbaString;
        ui->primaryColorButton->setStyleSheet(QString("background-color: rgba(%1)").arg(rgbaString));

        this->model->color = Vector4(chosenColor.red(), chosenColor.green(), chosenColor.blue(), chosenColor.alpha());
    }

}

/*
 * Sets the current drawing color to the color displayed on the partially hidden color button.
 * Swaps the colors shown on the primary/secondary button pair.
 */
void MainWindow::onSecondaryColorButtonClicked()
{
    // Swap the colors shown on the two buttons
    QString styleInfo = (ui->primaryColorButton->styleSheet());
    ui->primaryColorButton->setStyleSheet(ui->secondaryColorButton->styleSheet());
    ui->secondaryColorButton->setStyleSheet(styleInfo);

    // Swap the model's primary and secondary colors
    Vector4 temp(model->color.r, model->color.g, model->color.b, model->color.a);
    Vector4 temp2(model->secondaryColor.r, model->secondaryColor.g, model->secondaryColor.b, model->secondaryColor.a);
    model->color = temp2;
    model->secondaryColor = temp;
}


void MainWindow::onBrushButtonClicked()
{
    this->model->currentTool = "Pen";
    //this->setCursor(Qt::WaitCursor);
    this->ui->brushButton->setStyleSheet("border:2px solid black; background-color:#999999");
    this->ui->eraserButton->setStyleSheet("border:0; background-color:none");
    this->ui->bucketButton->setStyleSheet("border:0; background-color:none");

    QDir::setSearchPaths("icons", QStringList(QDir::homePath() + "/Repositories/u0930231/SpriteEditor/Resources_External/"));
    QPixmap map("icons:brush_black.png");
    map = map.scaled(35,35);
    setCursor(map);
}

void MainWindow::onEraserButtonClicked()
{
    this->model->currentTool = "Eraser";
    this->ui->eraserButton->setStyleSheet("border:2px solid black; background-color:#999999");
    this->ui->brushButton->setStyleSheet("border:0; background-color:none");
    this->ui->bucketButton->setStyleSheet("border:0; background-color:none");

    QDir::setSearchPaths("icons", QStringList(QDir::homePath() + "/Repositories/u0930231/SpriteEditor/Resources_External/"));
    QPixmap map("icons:eraser_black.png");
    map = map.scaled(35,35);
    setCursor(map);
}

void MainWindow::onBucketButtonClicked()
{
    this->model->currentTool = "Bucket";
    this->ui->bucketButton->setStyleSheet("border:2px solid black; background-color:#999999");
    this->ui->eraserButton->setStyleSheet("border:0; background-color:none");
    this->ui->brushButton->setStyleSheet("border:0; background-color:none");

    QDir::setSearchPaths("icons", QStringList(QDir::homePath() + "/Repositories/u0930231/SpriteEditor/Resources_External/"));
    QPixmap map("icons:fill_black.png");
    map = map.scaled(35,35);
    setCursor(map);
}
