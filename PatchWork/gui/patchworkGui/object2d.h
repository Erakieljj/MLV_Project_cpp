#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <string.h>
#include <vector>
#include <QGraphicsScene>
#include "point.h"
#include "objectinterface.h"
#include "matrix.h"
#include <QObject>

using namespace std;

/**
 * @brief The Object2D abstract class pour les formes
 */
class Object2D :public ObjectInterface {
    protected:
        /**
         * @brief color
         */
        std::string color;
        /**
         * @brief vertices vector de Points
         */
        vector<Point> vertices;
        /**
         * @brief mat la matrice de Points
         */
        Matrix mat;
        Object2D(std::string color): color(color){}

    public:
        //Personal method

        /**
         * @brief getArea retourne l'aire
         * @return float l'aire
         */
        virtual float getArea()=0;
        /**
         * @brief getPerimeter retourne le perimetre
         * @return float - le perimetre
         */
        virtual float getPerimeter()=0;
        /**
         * @brief getColor
         * @return
         */
        std::string getColor();
        /**
         * @brief setColor
         * @param color
         */
        void setColor(std::string color);
        /**
         * @brief getPoints retourne la liste des Points
         * @return
         */
        vector<Point> getPoints(){return this->vertices;}

        /**
         * @brief draw virtual pure a redefinir pour dessiner chaque forme
         */
        virtual void draw()=0;

        /**
         * @brief applyTranslation applique une translation a la matrice representant l'objet
         * @param x
         * @param y
         */
        void applyTranslation(double x,double y);
        /**
         * @brief applyRotationDirect applique une rotation dans le sens direct a la matrice
         * @param angle
         */
        void applyRotationDirect(double angle);
        /**
         * @brief applyRotationCentral applique une rotation centrale
         * @param angle radian
         * @param x
         * @param y
         */
        void applyRotationCentral(double angle,double x,double y);

        /**
         * @brief applyRotationIndirect
         * @param angle radion
         */
        void applyRotationIndirect(double angle);
        /**
         * @brief applyHomethety applique une homothety a la matrice
         * @param x double
         * @param y double
         */
        void applyHomethety(double x,double y);
        /**
         * @brief applyAxialSymmetry applique une symetrie axial
         * @param a
         * @param b
         */
        void applyAxialSymmetry(double a, double b);
        /**
         * @brief applyCentralSymmetry applique une symetrie central
         * @param x
         * @param y
         */
        void applyCentralSymmetry(double x,double y);

        virtual bool isLine(){return false;}
        virtual bool isEllipse(){return false;}
        virtual bool isPoly(){return false;}
        virtual bool isCircle(){return false;}

        /**
         * @brief getCenter retourne le Point au centre de la forme geometrique
         * @return a Point qui est le centre de la forme geometrique
         */
        virtual Point getCenter() =0;



private:
        void updateVertices();
};
#endif // OBJECT2D_H
