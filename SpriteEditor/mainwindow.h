#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_secondaryColorButton_clicked();

    void on_addFrameButton_clicked();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *framesLayout; //Used to nicely order the preview frames in the GUI
    int individualFrameWidth = 80;
    int individualFrameHeight = 80;
};

#endif // MAINWINDOW_H
