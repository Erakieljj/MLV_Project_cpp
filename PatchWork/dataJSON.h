#ifndef DATAJSON_H
#define DATAJSON_H

#include <map>
#include <QJsonObject>
#include <string>
#include "objectinterface.h"

static vector<ObjectInterface*> mShapes;

class DataJSON
{
    public:
        //DataJSON();

        const vector<ObjectInterface*> &shapes() const;
        static void setShapes(const vector<ObjectInterface*> &shapes);

        static void readDrawing(const QJsonObject &json);
        static void writeDrawing(QJsonObject &json);

};

#endif // DATAJSON_H
