#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include "point.h"
#include "fresque.h"

#include <vector>

enum mode{none,line,ellipse,circle,polygone};
class MyQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyQGraphicsView(QWidget *parent = 0);
    void updateModeLine();
    void updateModeEllipse();
    void updateModeCircle();
    void updateModePoly();
    void setRayon(double r){rayon = r;}
    void setPolygonPoint(double p){polygonPoint = p;}
    void setRlar(double r){rlar = r;}
    void setRlon(double r){rlon = r;}
    void setColorCircle(QString col){colorCircle = col;}
    void setColorEllipse(QString col){colorEllipse = col;}
    void setColorPolygone(QString col){colorPolygone = col;}
    void setColorLine(QString col){colorLine = col;}

    void applyHomo(QString forme,double hx,double hy);
    void applyTranslation(QString forme,double tx,double ty);
    void applyRotation(QString forme,double r);

    void callServer();



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
    mode m = none;
    int polygonPoint =5;
    Fresque *fresque;
    void draw();
    double rayon = 20;
    double rlon = 20;
    double rlar = 10;

    QString colorCircle = "black";
    QString colorLine = "black";
    QString colorEllipse = "black";
    QString colorPolygone = "black";


};

#endif
