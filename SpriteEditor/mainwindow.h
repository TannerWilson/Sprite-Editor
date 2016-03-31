#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include "vector.h"
#include <QGraphicsScene>
#include "model.h"
#include "spritegraphicsview.h"
#include <QPointF>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    QVBoxLayout *framesLayout; //Used to nicely order the preview frames in the GUI
    QVBoxLayout *graphicslayout;
    int individualFrameWidth = 80;
    int individualFrameHeight = 80;
    SpriteGraphicsView* spritegraphicsview;
    QGraphicsScene* scene;
    Model* model;
    void DrawGrid(int imageheight,int imagewidth, int unitsize);

private slots:
    void on_secondaryColorButton_clicked();

    void on_addFrameButton_clicked();

    void on_primaryColorButton_clicked();



public:
    explicit MainWindow(QWidget *parent = 0);
    void AddRect(float x, float y, float height, float width, Vector4 color);

    ~MainWindow();
};

#endif // MAINWINDOW_H
