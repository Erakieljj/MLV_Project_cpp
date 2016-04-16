#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QJsonDocument>
#include <QPushButton>
#include <QMouseEvent>
#include "point.h"
#include "fresque.h"

#include <vector>

/**
 * @brief Le mode actuelle du gui
 */

enum mode{none,line,ellipse,circle,polygone};
class MyQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyQGraphicsView(QWidget *parent = 0);
    /**
     * @brief change le mode actuelle en ligne
     */
    void updateModeLine();
    /**
     * @brief change le mode actuelle en ellipse
     */
    void updateModeEllipse();
    /**
     * @brief change le mode actuelle en circle
     */
    void updateModeCircle();
    /**
     * @brief change le mode actuelle en polynome
     */
    void updateModePoly();
    /**
     * @brief setRayon set le champs rayon du formulaire
     * @param r double, rayon
     */
    void setRayon(double r){rayon = r;}
    /**
     * @brief setPolygonPoint set le nombre de point pour le polygone formulaire
     * @param p double nombre de point
     */
    void setPolygonPoint(double p){polygonPoint = p;}
    /**
     * @brief setRlar set le champs Rlar de ellipse
     * @param r double rayon largeur ellipse
     */
    void setRlar(double r){rlar = r;}
    /**
     * @brief setRlon set le champs Rlon de ellipse
     * @param r double rayon longeur ellipse
     */
    void setRlon(double r){rlon = r;}

    /**
     * @brief setColorCircle set la couleur des cercles
     * @param col string color [red,blue,yellow,green,black]
     */
    void setColorCircle(QString col){colorCircle = col;}
    /**
     * @brief setColorEllipse set la couleur des ellipses
     * @param col string color [red,blue,yellow,green,black]
     */
    void setColorEllipse(QString col){colorEllipse = col;}
    /**
     * @brief setColorPolygone set la couleur des polygones
     * @param col string color [red,blue,yellow,green,black]
     */
    void setColorPolygone(QString col){colorPolygone = col;}
    /**
     * @brief setColorLine set la couleur des lignes
     * @param col string color [red,blue,yellow,green,black]
     */
    void setColorLine(QString col){colorLine = col;}

    /**
     * @brief applyHomo appliquer une homothetie a l'ensemble des formes demande
     * @param forme string [line,ellipse,circle,polygone]
     * @param hx double homothetie x ratio
     * @param hy double homothetie y ratio
     */
    void applyHomo(QString forme,double hx,double hy);
    /**
     * @brief applyTranslation appliquer une translation a l'ensemble des formes demande
     * @param forme string [line,ellipse,circle,polygone]
     * @param tx double translation x
     * @param ty double translation y
     */
    void applyTranslation(QString forme,double tx,double ty);
    /**
     * @brief applyRotation appliquer une rotation  d'angle r
     * @param forme string [line,ellipse,circle,polygone]
     * @param r double radian
     */
    void applyRotation(QString forme,double r);

    /**
     * @brief callServer envoie au serveur une representation du dessin actuelle
     */
    void callServer();

    void setDessin(QString filename);

    void applyReset();

    bool containCircle();
    bool containPolygone();
    bool containEllipse();
    bool containLine();

signals:

public slots:
    /**
     * @brief mousePressEvent mousse click event sur le qgraphicsRView
     * @param e event
     */
    void mousePressEvent(QMouseEvent * e);
    /**
     * @brief setMaxtPoint set le nombre de point a cliquer avant de dessiner la forme voulu
     * @param point int le nombre de point
     */
    void setMaxtPoint(int point);

    // void mouseReleaseEvent(QMouseEvent * e);
    // void mouseDoubleClickEvent(QMouseEvent * e);
    // void mouseMoveEvent(QMouseEvent * e);
private:
    /**
     * @brief scene de la qgraphicsView
     */
    QGraphicsScene * scene;
    /**
     * @brief currentPoint le nombre de point sur l'ecran
     */
    int currentPoint=0;
    /**
     * @brief maxPoint le nombre de point maximum avant de dessiner la forme
     */
    int maxPoint = -1;
    /**
     * @brief points la liste des Points créer
     */
    vector<Point> points;
    /**
     * @brief m le mode actuelle du GUI (creation de ellipse,line,circle,polygone)
     */
    mode m = none;
    /**
     * @brief polygonPoint nombre de point de base pour un polygone par defaut
     */
    int polygonPoint =5;
    /**
     * @brief fresque la Fresque du dessin
     */
    Fresque *fresque;
    /**
     * @brief draw dessine les élèments de la Fresque sur la Qgraphics view
     */
    void draw();
    /**
     * @brief rayon rayon des cercles par defaut
     */
    double rayon = 20;
    /**
     * @brief rlon rlon des ellipse par défauts
     */
    double rlon = 20;
    /**
     * @brief rlar des ellipses par défauts
     */
    double rlar = 10;

    /**
     * @brief colorCircle couleur par defauts des cercles
     */
    QString colorCircle = "black";
    /**
     * @brief colorLine couleur par défauts des lines
     */
    QString colorLine = "black";
    /**
     * @brief colorEllipse couleur par défauts des ellipses
     */
    QString colorEllipse = "black";
    /**
     * @brief colorPolygone couleurs par défauts des polygones
     */
    QString colorPolygone = "black";


};

#endif
