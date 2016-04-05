#ifndef SPRITEGRAPHICSVIEW_H
#define SPRITEGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class SpriteGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SpriteGraphicsView(QWidget *parent = 0);
signals:
    void MouseMoveSignal(QPointF point);
    void MousePressSignal(QPointF point);
    void MouseReleaseSignal(QPointF point);

public slots:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent (QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // SPRITEGRAPHICSVIEW_H
