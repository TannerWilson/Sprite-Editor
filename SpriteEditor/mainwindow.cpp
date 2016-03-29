#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
