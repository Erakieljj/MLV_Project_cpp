#include "dataJSON.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygone.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

void DataJSON::readShapeJSON(const QJsonObject &json, ObjectInterface *obj, float areaTotal, float perimeterTotal, string type,QGraphicsScene * scene)
{
    vector<Point> points;
    string color= json["color"].toString().toStdString();
    QJsonArray pointsArray = json["points"].toArray();

    for (int index = 0; index < pointsArray.size(); index++)
    {
        QJsonObject pointObjJSON = pointsArray[index].toObject();
        points.push_back(Point(pointObjJSON["x"].toDouble(), pointObjJSON["y"].toDouble()));
    }
   /* json["perimeter"].toDouble();
    json["area"].toDouble();*/
    if(type == "Line")
    {
        obj = new Line(color, points[0], points[1]);
    }
    else if(type == "Circle")
    {
        obj = new Circle(color, points[0], json["rayon"].toDouble());
    }
    else if(type == "Ellipse") {
       obj = new Ellipse(color, points[0], json["rlar"].toDouble(), json["rlong"].toDouble());
    }
    else if(type == "Polygone")
    {
        obj = new Polygone(color, points);
    }
    //json["matrix"];

}

const vector<ObjectInterface *> &DataJSON::getShapes()
{
    return mShapes;
}

void DataJSON::setShapes(const vector<ObjectInterface*> &shapes)
{
    mShapes = shapes;
}

vector<ObjectInterface *> DataJSON::readDrawing(const QJsonObject &json, Annotations notation)
{
    vector<ObjectInterface*> drawing;
    float areaTotal = 0.0;
    float perimeterTotal = 0.0;
    string color;

    QJsonObject shapes = json["shapes"].toObject();
    ObjectInterface *obj;

    readShapeJSON(shapes["Line"].toObject(), obj, areaTotal, perimeterTotal, "Line");
    drawing.push_back(obj);

    readShapeJSON(shapes["Circle"].toObject(), obj, areaTotal, perimeterTotal, "Circle");
    drawing.push_back(obj);

    readShapeJSON(shapes["Ellipse"].toObject(), obj, areaTotal, perimeterTotal, "Ellipse");
    drawing.push_back(obj);

    readShapeJSON(shapes["Polygone"].toObject(), obj, areaTotal, perimeterTotal, "Polygone");
    drawing.push_back(obj);

    // Annotation de la maîtresse.
    if (drawing.size() == 4)
    {
        notation.nbShapesRequired ="True";
    } else
    {
        notation.nbShapesRequired ="False";
    }


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

void DataJSON::writeJsonAnnotation(QJsonObject &json, Annotations notation)
{
    QString nbShapesRequired;
    QString nbColorAccepted = notation.nbColorAccepted;
    QString sumAreaAccepted = notation.sumAreaAccepted;
    float sumArea = notation.sumAreaShapeRequired;

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





