#include "dataJSON.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygone.h"

void DataJSON::setShapes(const map<string, std::unique_ptr<ObjectInterface>> &shapes)
{
    mShapes = shapes;
}

void DataJSON::readDrawing(const QJsonObject &json)
{
    QJsonObject shape;
    /*for (const auto& kv : mShapes) {
        std::cout << kv.first << " has value " << kv.second << std::endl;
    }*/
}

void DataJSON::writeDrawing(QJsonObject &json)
{

}




