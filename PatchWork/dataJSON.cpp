#include "dataJSON.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygone.h"

//static vector<ObjectInterface*> mShapes;

const vector<ObjectInterface *> &DataJSON::shapes()
{
    return mShapes;
}

void DataJSON::setShapes(const vector<ObjectInterface*> &shapes)
{
    mShapes = shapes;
}

void DataJSON::readDrawing(const QJsonObject &json)
{
    QJsonObject shape;
    for (ObjectInterface *obj : mShapes) {
        //obj->
    }
}

void DataJSON::writeDrawing(QJsonObject &json)
{

}

void DataJSON::writeJSONResponseServer(QJsonObject &json)
{

}




