#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include <string>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->update();
    ui->menuBar->activateWindow();

    ScreenHeight = 1000;
    ScreenWidth = 1000;

    // Set up stuff for the part of the GUI that allows you to add image frames,
    // browse image frames, etc.
    framesLayout = new QVBoxLayout(ui->frameContents);
    framesLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    //ui->frameContainer->setLayout(framesLayout);

    // Set up box layout for graphics frame
    graphicslayout = new QVBoxLayout;
    ui->graphicsframe->setLayout(graphicslayout);

    // Set the primary and secondary color choices
    ui->primaryColorButton->setStyleSheet("background-color: black");
    ui->secondaryColorButton->setStyleSheet("background-color: white");

    // Set up graphics scene for drawing
    scene = new QGraphicsScene(this);
    // Create model and pass scene pointer so it can draw to the screen.
    model = new Model(scene,ScreenHeight,ScreenWidth,25);

    // TODO Joey Set up what scene size based off image size.
    scene->setSceneRect(0,0,ScreenHeight,ScreenWidth);

    // Create graphics view
    spritegraphicsview = new SpriteGraphicsView();
    spritegraphicsview->setScene(scene);
    spritegraphicsview->setFixedSize(700, 700);
    spritegraphicsview->show();
    // Enable Mouse Events
    spritegraphicsview->setMouseTracking(true);

    // Connect mouse signals and slots
    connect (spritegraphicsview, SIGNAL(MouseMoveSignal(QPointF)),model, SLOT(MouseMove(QPointF)));
    connect(spritegraphicsview, SIGNAL(MouseClickedSignal(QPointF)), model, SLOT(MouseClicked(QPointF)));
    connect(spritegraphicsview, SIGNAL(MouseReleaseSignal(QPointF)), model, SLOT(MouseReleased(QPointF)));

    // Add the spritegraphicsview to the layout
    graphicslayout->addWidget(spritegraphicsview);
    graphicslayout->addStretch(1);

    GIFExport gifExport;

    // Connect menu bar actions
    connect(ui->actionSave, SIGNAL(triggered()), model, SLOT(Save()));
    connect(ui->actionOpen, SIGNAL(triggered()), model, SLOT(Open()));

    // pen is default tool
    this->ui->brushButton->setStyleSheet("border:2px solid black; background-color:#999999");
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
void MainWindow::on_addFrameButton_clicked()
{
    QPen pen(Qt::white, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QBrush brush; // Default brush does not fill in rectangle
    QGraphicsScene scene;
    scene.addRect(0,0,individualFrameWidth,individualFrameHeight,pen,brush);
    QGraphicsView *view = new QGraphicsView(&scene);
    view->setFixedSize(individualFrameWidth, individualFrameHeight);
    view->show();
    framesLayout->addWidget(view);
    frameWidgets.push_back(view);
    model->AddImage();
}

/*
 * Removes the selected frame from the Sprite.
 */
void MainWindow::on_deleteFrameButton_clicked()
{
    if(frameWidgets.size() > 0)
    {
        // Remove frame from GUI
        list<QGraphicsView*>::iterator it;
        it = frameWidgets.begin();
        advance (it, model->GetCurrentImageIndex());
        frameWidgets.erase(it);
        QWidget *frame = *it;
        layout()->removeWidget(frame);
        delete frame;

        // Remove frame from model
        model->RemoveImageAt(model->GetCurrentImageIndex());

        qDebug() << frameWidgets.size();


    }
}

/*
 * Opens the color picker, saves the selected color, and updates the primary and secondary
 * color choices
 */
void MainWindow::on_primaryColorButton_clicked()
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
void MainWindow::on_secondaryColorButton_clicked()
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




void MainWindow::on_brushButton_clicked()
{
    this->model->currentTool = "Pen";
    //this->setCursor(Qt::WaitCursor);
    this->ui->brushButton->setStyleSheet("border:2px solid black; background-color:#999999");
    this->ui->eraserButton->setStyleSheet("border:0; background-color:none");
    this->ui->bucketButton->setStyleSheet("border:0; background-color:none");
}

void MainWindow::on_eraserButton_clicked()
{
    this->model->currentTool = "Eraser";
    this->ui->eraserButton->setStyleSheet("border:2px solid black; background-color:#999999");
    this->ui->brushButton->setStyleSheet("border:0; background-color:none");
    this->ui->bucketButton->setStyleSheet("border:0; background-color:none");
}

void MainWindow::on_bucketButton_clicked()
{
    this->model->currentTool = "Bucket";
    this->ui->bucketButton->setStyleSheet("border:2px solid black; background-color:#999999");
    this->ui->eraserButton->setStyleSheet("border:0; background-color:none");
    this->ui->brushButton->setStyleSheet("border:0; background-color:none");
}
