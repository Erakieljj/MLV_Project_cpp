#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include "point.h"
#include <vector>

class MyQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyQGraphicsView(QWidget *parent = 0);

signals:

public slots:
    void mousePressEvent(QMouseEvent * e);
    void setMaxtPoint(int point);
    // void mouseReleaseEvent(QMouseEvent * e);
    // void mouseDoubleClickEvent(QMouseEvent * e);
    // void mouseMoveEvent(QMouseEvent * e);
private:
    QGraphicsScene * scene;
    int currentPoint=0;
    int maxPoint = -1;
    vector<Point> points;

};

#endif
