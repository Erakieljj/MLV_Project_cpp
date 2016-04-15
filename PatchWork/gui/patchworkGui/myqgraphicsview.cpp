#include "myqgraphicsview.h"
#include <QPointF>
#include <QtCore/QtDebug>
#include "point.h"
#include "line.h"
#include "ellipse.h"
#include "circle.h"
#include "polygone.h"
#include "client.h"

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

void MyQGraphicsView::applyHomo(QString forme,double hx,double hy)
{
    string f = forme.toUtf8().constData();
    if(f=="cercle"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isCircle())
                o->applyHomethety(hx,hy);
        }
    } else if(f=="ligne"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isLine())
                o->applyHomethety(hx,hy);
        }
    } else if(f=="ellipse"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isEllipse())
                o->applyHomethety(hx,hy);
        }
    } else {
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isPoly())
                o->applyHomethety(hx,hy);
        }
    }

    this->scene->clear();
    fresque->draw();
}

void MyQGraphicsView::applyTranslation(QString forme,double hx,double hy)
{
    qDebug() << "Called" ;
    string f = forme.toUtf8().constData();

    if(f=="cercle"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isCircle()){
                qDebug() << "Called" ;
                o->applyTranslation(hx,hy);
            } else{
                qDebug() << "FALSE" ;
            }
        }
    } else if(f=="ligne"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isLine())
                o->applyTranslation(hx,hy);
        }
    } else if(f=="ellipse"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isEllipse())
                o->applyTranslation(hx,hy);
        }
    } else {
        qDebug() << "WAT" ;
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isPoly())
                o->applyTranslation(hx,hy);
        }
    }
    this->scene->clear();
    fresque->draw();
}

void MyQGraphicsView::applyRotation(QString forme,double r)
{
    string f = forme.toUtf8().constData();
    if(f=="cercle"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isCircle()){
                Point p = o->getCenter();
                o->applyRotationCentral(r,p.get_x(),p.get_y());
            }
                //o->applyRotationDirect(r);

        }
    } else if(f=="ligne"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isLine()){
                Point p = o->getCenter();
                o->applyRotationCentral(r,p.get_x(),p.get_y());
            }
                //o->applyRotationDirect(r);

        }
    } else if(f=="ellipse"){
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isEllipse()){
                Point p = o->getCenter();
                o->applyRotationCentral(r,p.get_x(),p.get_y());
            }
                //o->applyRotationDirect(r);

        }
    } else {
        for(ObjectInterface *o :this->fresque->getObjects()){
            if(o->isPoly()){
                Point p = o->getCenter();
                o->applyRotationCentral(r,p.get_x(),p.get_y());
            }
                //o->applyRotationDirect(r);

        }
    }
    this->scene->clear();
    fresque->draw();
}

void MyQGraphicsView::draw(){
    scene->clear();
    switch(m) {
    case none:
        break;
    case line:
    {Line *l = new Line(colorLine.toUtf8().constData(),points.at(0),points.at(1),scene);
        fresque->add(*l);
        fresque->draw();
        maxPoint = 2;
        break;
    }
    case ellipse:{

        Ellipse *e = new Ellipse(colorEllipse.toUtf8().constData(),points.at(0),rlon,rlar,scene);
        fresque->add(*e);
        fresque->draw();
        maxPoint = 1;
        break;
    }
    case circle:
    {
        Circle *c = new Circle(colorCircle.toUtf8().constData(),points.at(0),rayon,scene);
        fresque->add(*c);
        fresque->draw();
        maxPoint = 1;
        break;
    }
    case polygone:
        Polygone *p = new Polygone(colorPolygone.toUtf8().constData(),points,scene);
        fresque->add(*p);
        fresque->draw();
        maxPoint = polygonPoint;
        break;
    }
}

void MyQGraphicsView::callServer(){
    //parse fresque
    /*
    DataJSON::setShapes(this->fresque->getObjects());
    QJsonObject objJSONWrite;
    QJsonObject objJSON;
    DataJSON::writeDrawing(objJSON);
    */
    Client *c = new Client();
    c->start("hello");
}
