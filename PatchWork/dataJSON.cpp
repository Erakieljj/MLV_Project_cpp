#include "dataJSON.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygone.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

void DataJSON::readShapeJSON(const QJsonObject &json, ObjectInterface &obj)
{
    shape["color"];
    QJsonArray pointsArray = shape["points"].toArray();
    for (int index = 0; index < pointsArray.size(); index++)
    {
        QJsonObject pointObjJSON = pointsArray[index].toObject();
        pointObjJSON["x"];
        pointObjJSON["y"];
    }
    shape["perimeter"];
    shape["area"];
    shape["matrix"];
}

const vector<ObjectInterface *> &DataJSON::getShapes()
{
    return mShapes;
}

void DataJSON::setShapes(const vector<ObjectInterface*> &shapes)
{
    mShapes = shapes;
}

vector<ObjectInterface *> DataJSON::readDrawing(const QJsonObject &json)
{
    vector<ObjectInterface*> drawing;
    QJsonObject shapes = json["shapes"].toObject();
    ObjectInterface *obj;

    readShapeJSON(shapes["Line"].toObject(), obj);
    drawing.push_back(obj);

    readShapeJSON(shapes["Circle"].toObject(), obj);
    drawing.push_back(obj);

    readShapeJSON(shapes["Ellipse"].toObject(), obj);
    drawing.push_back(obj);

    readShapeJSON(shapes["Polygone"].toObject(), obj);
    drawing.push_back(obj);

    return drawing;
}

void DataJSON::writeDrawing(QJsonObject &json)
{
    for (ObjectInterface *obj : mShapes)
    {
        QString type = QString::fromLatin1(obj->metaObject()->className());
        QJsonObject shapeJSON;

        //cout<<obj->metaObject()->className()<<endl;

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
        //shapeJSON["matrix"] = obj->mat;
        json.insert(QString("shapes"), QJsonValue(shapeJSON));
    }
}

void DataJSON::writeJsonAnnotation(QJsonObject &json)
{
    QString nbColorAccepted = "2";
    QString nbShapesRequired;
    QString sumAreaAccepted = "30";
    float sumArea;

    if (mShapes.size() > 2)
        nbShapesRequired = "False";
    else
        nbShapesRequired = "True";

    QJsonObject annotationsJSON;
    annotationsJSON["nbColorAccepted"] = nbColorAccepted;

    annotationsJSON["nbShapeRequired"] = nbShapesRequired;
    annotationsJSON["sumAreaShapeAccepted"] = sumAreaAccepted;
    annotationsJSON["sumAreaShapeRequired"] = sumArea;
    //json.insert(QString("studentID"), QJsonValue(annotationsJSON));
    json.insert(QString("annotations"), QJsonValue(annotationsJSON));
}

Annotations DataJSON::readJsonAnnotation(QJsonObject &json)
{
    Annotations notation;

    QJsonObject annotationsJSON = json["annotations"].toObject();
    notation.nbColorAccepted = annotationsJSON.value("nbColorAccepted").toString();
    notation.nbShapesRequired = annotationsJSON.value("nbShapeRequired").toString();
    notation.sumAreaAccepted = annotationsJSON.value("sumAreaShapeAccepted").toString();
    notation.sumAreaShapeRequired = annotationsJSON.value("sumAreaShapeRequired").toDouble();

    return notation;
}





