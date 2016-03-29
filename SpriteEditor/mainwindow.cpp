#include "mainwindow.h"
#include "ui_mainwindow.h"

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
