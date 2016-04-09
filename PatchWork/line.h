#ifndef LINE_H
#define LINE_H
#include "object2d.h"

class Line : public Object2D
{
    public:
        Line();
        ~Line();
        // Inherited method from Object2D
        float getArea();
        float getPerimeter();

        // Inherited method from ObjectInterface
        void draw();
        void applyTranslation(float x,float y);
        void applyRotationDirect(float angle);
        void applyRotationIndirect(float angle);
        void applyHomethety(float ratio);
        void applyAxialSymmetry();
        void applyCentralSymmetry();
};

#endif // LINE_H
