#include "myqgraphicsview.h"
#include <QPointF>
#include <QtCore/QtDebug>
#include "point.h"
#include <QtDebug>
using namespace std;

MyQGraphicsView::MyQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    this->setSceneRect(50, 50, 350, 350);
    this->setScene(scene);
}

void MyQGraphicsView::mousePressEvent(QMouseEvent * e)
{
    double rad = 1;
    QPointF pt = mapToScene(e->pos());

    scene->addEllipse(pt.x()-rad, pt.y()-rad, rad*5.0, rad*5.0,
        QPen(), QBrush(Qt::SolidPattern));
    if(points.size()>0) {
        Point p = points.at(points.size()-1);
        QPointF pf = mapToScene(p.get_x(),p.get_y());
        qDebug() << e->pos();
        qDebug() << points.size();
        scene->addLine(pt.x(),pt.y(),pf.x(),pf.y(),*(new QPen(Qt::red,5)));

    }
    points.push_back(*(new Point(e->pos().x(),e->pos().y())));




}

void MyQGraphicsView::setMaxtPoint(int point)
{
    this->maxPoint = point;
}
