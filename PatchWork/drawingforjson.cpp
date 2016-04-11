#include "drawingforjson.h"

DrawingForJSON::DrawingForJSON()
{

}

void DrawingForJSON::read(const QJsonObject &json)
{
    mShapes.clear();
    QJsonArray shapesArray = json["shapes"].toArray();
    for(int shapesIndex = 0; shapesIndex < shapesArray.size(); shapesIndex++) {
        QJsonObject shapeObject = shapesArray[shapesIndex].toObject();
        ObjectInterface shape;
        shape.read(shapeObject);
        mShapes.append(shape);
    }
}

void DrawingForJSON::write(QJsonObject &json) const
{
    QJsonArray shapesArray;
    for(int i = 0; i < mShapes.size(); i++) {
        QJsonObject shapeObject;
        mShapes.at(i).write(shapeObject);
        shapesArray.append(shapeObject);
    }
    json["shapes"] = shapesArray;
}
