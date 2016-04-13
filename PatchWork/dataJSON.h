#ifndef DATAJSON_H
#define DATAJSON_H

#include <memory>
#include <map>
#include <QJsonObject>
#include <string>
#include "objectinterface.h"

class DataJSON
{
    public:
        DrawingForJSON();

        const map<string, std::unique_ptr<ObjectInterface>> &shapes() const;
        static void setShapes(const map<string, std::unique_ptr<ObjectInterface>> &shapes);

        static void readDrawing(const QJsonObject &json);
        static void writeDrawing(QJsonObject &json);

    private:
        static map<string, std::unique_ptr<ObjectInterface>> mShapes;
};

#endif // DATAJSON_H
