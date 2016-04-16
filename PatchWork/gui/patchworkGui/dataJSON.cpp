#include "dataJSON.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygone.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <set>
#include <QtCore/QtDebug>


void DataJSON::readDrawingAndCheck(QJsonObject &json, QJsonObject &notation)
{
    set<QString> colors;

    QStringList keys = json.keys();
    notation["NumberShape"] = keys.size();

    for(QString key : keys)
    {
        colors.insert((json[key].toObject())["color"].toString());
    }

    notation["NumberColor"] = static_cast<int>(colors.size());

}

void DataJSON::writeDrawing(vector<ObjectInterface *> shapes, QJsonObject &json)
{
    for (ObjectInterface *obj : shapes)
    {
        QString type = QString::fromLatin1(obj->metaObject()->className());
        QJsonObject shapeJSON;

        cout<<obj->metaObject()->className()<<endl;

        shapeJSON["color"] = QString::fromStdString(obj->getColor());
        QJsonArray pointsArray;
        for(Point point : obj->getPoints())
        {
           QJsonObject pointObjJSON;
           pointObjJSON["x"] = point.get_x();
           pointObjJSON["y"] = point.get_y();
           pointsArray.append(pointObjJSON);
        }
        shapeJSON["points"] = pointsArray;
        shapeJSON["perimeter"] = obj->getPerimeter();
        shapeJSON["area"] = obj->getArea();

        if (type == "Circle")
        {
            Circle* circle = (Circle*)obj;
            shapeJSON["rayon"] = circle->getRayon();
        }
        else if (type == "Ellipse")
        {
            Ellipse* ellipse =(Ellipse*)obj;
            shapeJSON["rlar"] = ellipse->getRlar();
            shapeJSON["rlong"] = ellipse->getRlon();

        }
        /*else if (type == "Fresque") {
            Fresque *fresque = (Fresque*)obj;
        }*/

        json.insert(type, QJsonValue(shapeJSON));
    }
}

string DataJSON::readJsonAnnotation(QJsonObject &json)
{
    int nbShape = json["NumberShape"].toInt();
    int nbColor = json["NumberColor"].toInt();

    if(nbShape >= 2 && nbColor >= 2)
    {
        return "";
    }
    else
    {
        return "nombre de couleur ( " + to_string(nbColor) + ") et nombre forme ( " + to_string(nbShape) + " ) doivent etre superieur à 2";
    }
}

Fresque* DataJSON::read(string jsonO)
{
    QJsonObject obj = QJsonDocument::fromJson(QString::fromStdString(jsonO).toUtf8()).object();
    Fresque *fresque = new Fresque();
    QJsonArray pointsArray;


    if(obj.contains("Circle"))
    {
        QJsonObject circleJson = obj["Circle"].toObject();
        pointsArray = circleJson["points"].toArray();
        vector<Point> points;
        foreach (const QJsonValue & value, pointsArray) {
            QJsonObject obj = value.toObject();
            points.push_back(Point(obj["x"].toDouble(), obj["y"].toDouble()));
        }
        Circle *circle = new Circle(circleJson["color"].toString().toStdString(), points[0], circleJson["rayon"].toDouble());
        fresque->add(*circle);
    }
    if(obj.contains("Ellipse"))
    {
        QJsonObject ellipseJson = obj["Circle"].toObject();
        pointsArray = ellipseJson["points"].toArray();
        vector<Point> points;
        foreach (const QJsonValue & value, pointsArray) {
            QJsonObject obj = value.toObject();
            points.push_back(Point(obj["x"].toDouble(), obj["y"].toDouble()));
        }
        Ellipse *ellipse = new Ellipse(ellipseJson["color"].toString().toStdString(), points[0], ellipseJson["rlong"].toDouble(), ellipseJson["rlar"].toDouble());
        fresque->add(*ellipse);
    }
    if(obj.contains("Line"))
    {
        QJsonObject lineJson = obj["Line"].toObject();
        pointsArray = lineJson["points"].toArray();
        vector<Point> points;
        foreach (const QJsonValue & value, pointsArray) {
            QJsonObject obj = value.toObject();
            points.push_back(Point(obj["x"].toDouble(), obj["y"].toDouble()));
        }
        Line *line = new Line(lineJson["color"].toString().toStdString(), points[0], points[1]);
        fresque->add(*line);
    }
    if(obj.contains("Polygone"))
    {
        QJsonObject polygonJson = obj["Polygone"].toObject();
        pointsArray = polygonJson["points"].toArray();
        vector<Point> points;
        foreach (const QJsonValue & value, pointsArray) {
            QJsonObject obj = value.toObject();
            points.push_back(Point(obj["x"].toDouble(), obj["y"].toDouble()));
        }
        Polygone *polygon = new Polygone(polygonJson["color"].toString().toStdString(), points);
        fresque->add(*polygon);
    }
    return fresque;
}

Fresque* DataJSON::readFromFile(QString pathfile)
{
     QString val;
     QFile file;
     file.setFileName(pathfile);
     file.open(QIODevice::ReadOnly | QIODevice::Text);
     val = file.readAll();
     file.close();
     return read(val.toStdString());
}

