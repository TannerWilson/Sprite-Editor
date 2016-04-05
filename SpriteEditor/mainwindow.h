#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include "vector.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "model.h"
#include "spritegraphicsview.h"
#include <QPointF>
#include <gifexport.h>

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
    QVBoxLayout *graphicsLayout;
    int individualFrameWidth = 80;
    int individualFrameHeight = 80;
    std::list<QPushButton*> frameWidgets;
    SpriteGraphicsView* spriteGraphicsView;
    QGraphicsScene* scene;
    Model* model;
    void drawGrid(int imageheight,int imagewidth, int unitsize);

    int screenWidth;
    int screenHeight;

private slots:
    void onSecondaryColorButtonClicked();

    void onAddFrameButtonClicked();

    void onFrameButtonClicked();

    void onPrimaryColorButtonClicked();

    void onDeleteFrameButtonClicked();

    void onBrushButtonClicked();

    void onEraserButtonClicked();

    void onBucketButtonClicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    void addRect(float x, float y, float height, float width, Vector4 color);

    ~MainWindow();
};

#endif // MAINWINDOW_H
