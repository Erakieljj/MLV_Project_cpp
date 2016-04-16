#include <iostream>

#include "point.h"
#include "line.h"
#include "circle.h"
#include "polygone.h"
#include "ellipse.h"
#include "fresque.h"
#include "objectinterface.h"
#include "matrix.h"
#include "client.h"
//#include "clientgui.h"
using namespace std;

#include <iostream>

#include "point.h"
#include "ellipse.h"
#include "line.h"
#include "circle.h"
#include "polygone.h"
#include "fresque.h"
#include "objectinterface.h"
#include "dataJSON.h"
#include "matrix.h"
#include <QJsonDocument>
//#include "clientgui.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*
    Fresque *f = new Fresque();*/

    Point p(1,2);
    Point p2(5,2);

    ObjectInterface *l = new Line("red",p,p2);
    ObjectInterface *c = new Circle("blue",Point(5,7),10);

    //ObjectInterface *e = new Ellipse("blue",Point(54,70),10,30);
    ObjectInterface *pol = new Polygone("black",{Point(4,6),Point(5,7),Point(44,65),Point(24,6),Point(4,76)});

    /*f->add(*l);
    f->add(*c);
    f->add(*e);
    f->add(*pol);
    cout << " AFFICHAGE DE LA FRESQUE"<<endl;
    f->draw();
    f->applyHomethety(5,6);
    cout << " AFFICHAGE DE LA FRESQUE apres homothety 5,6"<<endl;
    f->draw();
    cout<<endl<<" BILAN" <<endl;
    cout << "AREA " << f->getArea() << "  Perimeter :" <<f->getPerimeter() <<endl;
    cout <<endl;

    */
    /*
    Matrix *m1 = new Matrix(3,7);
    Matrix *m2 = Matrix::idMatrix(3);
    Matrix m3 = Matrix::axialSymmetry(2,4);
    Matrix *m4 = Matrix::rotationDirect(90);
    Matrix *m5 = Matrix::translation(10,4);
    m1->print();
    m2->print();
    m3.print();
    m4->print();
    m5->print();

    // Representation matricielle du vecteur de Point
    Matrix *m6 = new Matrix(l->getPoints());

    // Matrix de homothetie * Matrix reprensenté par notre Line

    m6->print();

    try{
        Matrix mm = m3 * (*m6) ;
        mm.print();
    } catch(domain_error* e){
        cout <<e->what() <<endl;
    }
    */
    /*Q_INIT_RESOURCE(clientgui);

    QApplication app(argc, argv);
    Window window;
    window.show();
    return app.exec();*/

    vector<ObjectInterface*> shapes;

    shapes.push_back(l);
    //shapes.push_back(e);
    shapes.push_back(c);
    shapes.push_back(pol);


    QJsonObject objJSONWrite;
    QJsonObject objJsonAnnotation;

    QJsonDocument jsonDoc;

    DataJSON::writeDrawing(shapes, objJSONWrite);
    jsonDoc.setObject(objJSONWrite);
    QString strJson(jsonDoc.toJson(QJsonDocument::Compact));
    cout<<strJson.toStdString()<<endl;

    DataJSON::readDrawingAndCheck(objJSONWrite, objJsonAnnotation);

    Fresque *fresque = DataJSON::read(strJson.toStdString());
    cout << "affichage de la fresque: " << endl;
    fresque->draw();

    Client* c1 = new Client();
    (*c1).start(strJson.toStdString());

    return 0;
}


