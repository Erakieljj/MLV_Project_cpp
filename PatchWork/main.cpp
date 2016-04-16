#include <iostream>

#include "point.h"
#include "line.h"
#include "circle.h"
#include "polygone.h"
#include "ellipse.h"
#include "fresque.h"
#include "objectinterface.h"
#include "matrix.h"
#include "client.h"
#include "dataJSON.h"
//#include "clientgui.h"

using namespace std;

/*string createDrawings(Line &line, Circle &circle, Polygone *polygone, Ellipse *ellipse = 0) {
    QJsonObject objJSONWrite;
    QJsonDocument jsonDoc;
    vector<ObjectInterface*> shapes;

    DataJSON::writeDrawing(shapes, objJSONWrite);
    jsonDoc.setObject(objJSONWrite);
    QString strJson(jsonDoc.toJson(QJsonDocument::Compact));
    cout<<strJson.toStdString()<<endl;

    shapes.push_back(line);
    //shapes.push_back(e);
    shapes.push_back(circle);
    shapes.push_back(polygone);

    DataJSON::writeDrawing(shapes1, objJSONWrite);
    jsonDoc.setObject(objJSONWrite);
    QString strJson(jsonDoc.toJson(QJsonDocument::Compact));
    cout<<strJson.toStdString()<<endl;

    return strJson.toStdString();
}*/

int main(int argc, char *argv[])
{

    Point p(1,2);
    Point p2(5,2);

    ObjectInterface *l = new Line("blue",p,p2);
    ObjectInterface *c = new Circle("blue",Point(5,7),10);
    //ObjectInterface *e = new Ellipse("blue",Point(54,70),10,30);
    ObjectInterface *pol = new Polygone("blue",{Point(4,6),Point(5,7),Point(44,65),Point(24,6),Point(4,76)});

    ObjectInterface *l1 = new Line("red",p,p2);
    ObjectInterface *ci1 = new Circle("blue",Point(5,7),10);
    //ObjectInterface *e1 = new Ellipse("black",Point(54,70),10,30);
    ObjectInterface *pol1 = new Polygone("black",{Point(4,6),Point(5,7),Point(44,65),Point(24,6),Point(4,76)});


    vector<ObjectInterface*> shapes;
    vector<ObjectInterface*> shapes1;

    shapes.push_back(l);
    //shapes.push_back(e);
    shapes.push_back(c);
    shapes.push_back(pol);


    QJsonObject objJSONWrite;

    QJsonDocument jsonDoc;

    DataJSON::writeDrawing(shapes, objJSONWrite);
    jsonDoc.setObject(objJSONWrite);
    QString strJson(jsonDoc.toJson(QJsonDocument::Compact));
    cout<<strJson.toStdString()<<endl;

    shapes1.push_back(l1);
    //shapes1.push_back(e);
    shapes1.push_back(ci1);
    shapes1.push_back(pol1);

    DataJSON::writeDrawing(shapes1, objJSONWrite);
    jsonDoc.setObject(objJSONWrite);
    QString strJson1(jsonDoc.toJson(QJsonDocument::Compact));
    cout<<strJson1.toStdString()<<endl;


    /*QJsonObject objJsonAnnotation;
    DataJSON::readDrawingAndCheck(objJSONWrite, objJsonAnnotation);*/

    /*Fresque *fresque = DataJSON::read(strJson.toStdString());
    cout << "affichage de la fresque: " << endl;
    fresque->draw();*/

    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int n4 = 4;
    Client* c1 = new Client(n1);
    Client* c2 = new Client(n2);
    Client* c3 = new Client(n3);
    //Client* c4 = new Client(n4);
    (*c1).start(strJson1.toStdString());
    (*c2).start(strJson1.toStdString());
    (*c3).start(strJson1.toStdString());
    //(*c4).start(strJson.toStdString());


    return 0;
}


