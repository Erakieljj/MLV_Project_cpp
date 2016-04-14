#include "myqgraphicsview.h"
#include <QPointF>
#include <QtCore/QtDebug>
#include "point.h"
#include "line.h"
#include "ellipse.h"
#include "circle.h"
#include "polygone.h"
#include <QtDebug>
using namespace std;

MyQGraphicsView::MyQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    this->fresque = new Fresque(scene);
    this->setSceneRect(50, 50, 350, 350);
    this->setScene(scene);
}

void MyQGraphicsView::mousePressEvent(QMouseEvent * e)
{
    if(this->m == none) {
        return;
    }
    double rad = 1;
    QPointF pt = mapToScene(e->pos());

    scene->addEllipse(pt.x()-rad, pt.y()-rad, rad*5.0, rad*5.0,
                      QPen(), QBrush(Qt::SolidPattern));
    this->maxPoint -=1;
    points.push_back(*(new Point(pt.x()-rad,pt.y()-rad)));
    qDebug() <<pt.x() << pt.y();
    qDebug() <<this->maxPoint << points.size();


    if(this->maxPoint==0 && points.size()>0){
        this->draw();
        points.clear();
    }

}

void MyQGraphicsView::setMaxtPoint(int point)
{
    this->maxPoint = point;
}

void MyQGraphicsView::updateModeLine()
{
    this->m = line;
}
void MyQGraphicsView::updateModeCircle()
{
    this->m = circle;
}
void MyQGraphicsView::updateModeEllipse()
{
    this->m = ellipse;
}
void MyQGraphicsView::updateModePoly()
{
    this->m = polygone;
}

void MyQGraphicsView::draw(){
    scene->clear();
    switch(m) {
    case none:
        break;
    case line:
    {Line *l = new Line("red",points.at(0),points.at(1),scene);
        fresque->add(*l);
        fresque->draw();
        maxPoint = 2;
        break;
    }
    case ellipse:{

        Ellipse *e = new Ellipse("red",points.at(0),rlon,rlar,scene);
        fresque->add(*e);
        fresque->draw();
        maxPoint = 1;
        break;
    }
    case circle:
    {
        Circle *c = new Circle("red",points.at(0),rayon,scene);
        fresque->add(*c);
        fresque->draw();
        maxPoint = 1;
        break;
    }
    case polygone:
        Polygone *p = new Polygone("red",points,scene);
        fresque->add(*p);
        fresque->draw();
        maxPoint = polygonPoint;
        break;
    }
}
