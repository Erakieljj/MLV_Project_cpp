#ifndef DATAJSON_H
#define DATAJSON_H

#include <QJsonObject>
#include <string>
#include "objectinterface.h"
#include "fresque.h"

using namespace std;
/**
 * @brief La classe DataJSON permet la gestion d'un document JSON dans les interactions client/serveur.
 * Cette classe fournit uniquement des méthodes statiques.
 */
class DataJSON
{
    public:
        //DataJSON();
        /**
         * @brief readDrawingAndCheck Lecture d'un JSON pour parser le dessin d'un élève (coté serveur).
         * @param json JSON à lire et parser.
         * @param notation annotation laissé par la maîtresse.
         */
        static void readDrawingAndCheck(QJsonObject &json , QJsonObject &notation);
        /**
         * @brief writeDrawing Ecriture d'un JSON associé au format de dessin d'un élève(coté client).
         * @param shapes list des formes géométriques.
         * @param json JSON à créer.
         */
        static void writeDrawing(vector<ObjectInterface*> shapes, QJsonObject &json);
        /**
         * @brief readJsonAnnotation Lecture d'un JSON contenant les annotations de la maîtresse (provenant du serveur).
         * @param json JSON à lire et parser.
         * @return Retourne les annotation de la maîtresse.
         */
        static string readJsonAnnotation(QJsonObject &json);
        /**
         * @brief read Création de la fresque.
         * @param jsonO Annotations de la maîtresse.
         * @return Retourne la fresque des dessins des élèves.
         */
        static Fresque* read(string jsonO,QGraphicsScene *scene);

};

#endif // DATAJSON_H
