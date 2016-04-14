#ifndef DATAJSON_H
#define DATAJSON_H

//#include <memory>
#include <map>
#include <QJsonObject>
#include <string>
#include "objectinterface.h"

class DataJSON
{
    public:
        DrawingForJSON();

        const map<string, ObjectInterface> &shapes() const; //std::unique_ptr<ObjectInterface>>'
        static void setShapes(const map<string, ObjectInterface> &shapes);

        static void readDrawing(const QJsonObject &json);
        static void writeDrawing(QJsonObject &json);

    private:
        static map<string, ObjectInterface> mShapes;
};

#endif // DATAJSON_H
