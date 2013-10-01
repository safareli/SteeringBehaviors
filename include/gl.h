#ifndef GL_H
#define GL_H
#include "Color.h"
namespace GL{
    void init();
    void update();
    void background(Color c);
    void circle(double cx, double cy, double r,bool fill);
    void line(double x, double y, double r,double theta);
    void color(Color c);

}

#endif // GL_H
