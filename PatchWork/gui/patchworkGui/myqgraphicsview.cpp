#include "myqgraphicsview.h"
#include <QPointF>
#include <QProgressBar>
#include <QInputDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QtCore/QtDebug>
#include <dataJSON.h>
#include "point.h"
#include "line.h"
#include "ellipse.h"
#include "circle.h"
#include "polygone.h"
#include "client.h"
#include "mainwindow.h"
#include <QtDebug>
using namespace std;

MyQGraphicsView::MyQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    this->fresque = new Fresque();
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
    fresque->draw(this->scene);
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
    fresque->draw(this->scene);
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
    fresque->draw(this->scene);
}

void MyQGraphicsView::draw(){
    scene->clear();
    MainWindow* parent = qobject_cast<MainWindow*>(this->parent());

    switch(m) {
    case none:
        break;
    case line:
    {Line *l = new Line(colorLine.toUtf8().constData(),points.at(0),points.at(1));
        fresque->add(*l);
        fresque->draw(this->scene);
        maxPoint = 2;
        break;
    }
    case ellipse:{
        Ellipse *e = new Ellipse(colorEllipse.toUtf8().constData(),points.at(0),rlon,rlar);
        fresque->add(*e);
        fresque->draw(this->scene);
        maxPoint = 1;
        break;
    }
    case circle:
    {
        Circle *c = new Circle(colorCircle.toUtf8().constData(),points.at(0),rayon);
        fresque->add(*c);
        fresque->draw(this->scene);
        maxPoint = 1;
        break;
    }
    case polygone:
        Polygone *p = new Polygone(colorPolygone.toUtf8().constData(),points);
        fresque->add(*p);
        fresque->draw(this->scene);
        maxPoint = polygonPoint;
        break;
    }
}

void MyQGraphicsView::callServer(){
    //parse fresque

    bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                         tr("User id:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
    {
        QJsonObject objJsonFresque;
        QJsonObject objJsonAnnotation;

        QJsonDocument jsonDoc;

        DataJSON::writeDrawing(this->fresque->getObjects(), objJsonFresque);
        jsonDoc.setObject(objJsonFresque);
        QString strJson(jsonDoc.toJson(QJsonDocument::Compact));
        //cout<<strJson.toStdString()<<endl;
        //DataJSON::readDrawingAndCheck(objJSONWrite, objJsonAnnotation);

        //Fresque *f = DataJSON::read(strJson.toStdString(),this->scene);
        //f->draw(this->scene);

        try{
            Client *c = new Client(text.toStdString());
            c->start(strJson.toStdString());
            QProgressBar *progressBar = new QProgressBar();
            progressBar->setMaximum(100);
            progressBar->setValue(100);
            progressBar->setTextVisible(true);
            progressBar->show();

        } catch(runtime_error e){
            QMessageBox msgBox;
            msgBox.setText("Probleme de serveur, vérifier que vous l'avez bien allumez");
            msgBox.exec();
        }
    }
}




void MyQGraphicsView::setDessin(QString filename){
    Fresque *f = DataJSON::readJsonFile(filename);
    fresque->setObject(f->getObjects());

}

void MyQGraphicsView::applyReset(){
    this->scene->clear();
    this->fresque->setObject(*(new vector<ObjectInterface*>));
}

bool MyQGraphicsView::containCircle(){
    for(ObjectInterface *o : this->fresque->getObjects()){
        if(o->isCircle())
            return true;
    }
    return false;
}

bool MyQGraphicsView::containEllipse(){
    for(ObjectInterface *o : this->fresque->getObjects()){
        if(o->isEllipse())
            return true;
    }
    return false;
}

bool MyQGraphicsView::containLine(){
    for(ObjectInterface *o : this->fresque->getObjects()){
        if(o->isLine())
            return true;
    }
    return false;
}

bool MyQGraphicsView::containPolygone(){
    for(ObjectInterface *o : this->fresque->getObjects()){
        if(o->isPoly())
            return true;
    }
    return false;
}
