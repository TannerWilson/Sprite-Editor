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

    ScreenHeight = 1000;
    ScreenWidth = 1000;

    // Set up stuff for the part of the GUI that allows you to add image frames,
    // browse image frames, etc.
    framesLayout = new QVBoxLayout;
    ui->frameContainer->setLayout(framesLayout);

    // Set up box layout for graphics frame
    graphicslayout = new QVBoxLayout;
    ui->graphicsframe->setLayout(graphicslayout);

    // Set the primary and secondary color choices
    ui->primaryColorButton->setStyleSheet("background-color: red");
    ui->secondaryColorButton->setStyleSheet("background-color: yellow");

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

}

MainWindow::~MainWindow()
{
    delete ui;
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
    framesLayout->addStretch(1);
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
        ui->secondaryColorButton->setStyleSheet(ui->primaryColorButton->styleSheet());
        QString rgbaString = QString("%1, %2, %3, %4").arg(chosenColor.red()).arg(chosenColor.green()).arg(chosenColor.blue()).arg(chosenColor.alpha());
        qDebug() << rgbaString;
        ui->primaryColorButton->setStyleSheet(QString("background-color: rgba(%1)").arg(rgbaString));
    }

}


