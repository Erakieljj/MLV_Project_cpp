#ifndef OBJECT2D_H
#define OBJECT2D_H
#include <string.h>
#include <vector>
#include "point.h"

    using namespace std;

    class Object2D {
        protected:
            Object2D(std::string, vector<Point>);
        public:
            std::string color; // le type peut changer
            vector<Point> vertices;

            createObject2D();
            applyTranslation(Object2D obj);
            applyHomothetie(Object2D obj);
            applySymCentral(Object2D obj);
            applySymAxial(Object2D obj);
            applyRotationX(Object2D obj);
            applyRotationY(Object2D obj);
    };

#endif // OBJECT2D_H
