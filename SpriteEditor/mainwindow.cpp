#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up stuff for the part of the GUI that allows you to add image frames,
    // browse image frames, etc.
    framesLayout = new QVBoxLayout;
    ui->frameContainer->setLayout(framesLayout);

    // Set the primary and secondary color choices
    ui->primaryColorButton->setStyleSheet("background-color: red");
    ui->secondaryColorButton->setStyleSheet("background-color: yellow");

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Sets the current drawing color to the color displayed on the partially hidden color button.
// Swaps the colors shown on the primary/secondary button pair.
void MainWindow::on_secondaryColorButton_clicked()
{
    // Swap the colors shown on the two buttons
    QString styleInfo = (ui->primaryColorButton->styleSheet());
    ui->primaryColorButton->setStyleSheet(ui->secondaryColorButton->styleSheet());
    ui->secondaryColorButton->setStyleSheet(styleInfo);


}

// Creates a new, blank image frame for the Sprite, shown on the left of the GUI.
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
