#ifndef GL_H
#define GL_H
#include "Color.h"
namespace GL{
    void init();
    void update();
    void background(Color c);
    //void ellipse (double x, double y, double width, double height,double angle = 0);
    void circle(double cx, double cy, double r);

    void color(Color c);

}

#endif // GL_H
