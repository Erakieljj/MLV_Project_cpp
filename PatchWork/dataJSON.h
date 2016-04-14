#ifndef DATAJSON_H
#define DATAJSON_H

#include <map>
#include <QJsonObject>
#include <string>
#include "objectinterface.h"

static vector<ObjectInterface*> mShapes; //penser au clear et init
/**
 * @brief La classe DataJSON permet la gestion d'un document JSON dans les interactions client/serveur.
 * Cette classe fournit uniquement des méthodes statiques.
 */
class DataJSON
{
    public:
        //DataJSON();

        static const vector<ObjectInterface*> &shapes();
        static void setShapes(const vector<ObjectInterface*> &shapes);

        static void readDrawing(const QJsonObject &json);
        static void writeDrawing(QJsonObject &json);
        static void writeJSONResponseServer(QJsonObject &json);

};

#endif // DATAJSON_H
