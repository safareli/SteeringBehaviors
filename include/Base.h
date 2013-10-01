#ifndef BASE_H
#define BASE_H

#include "../include/Color.h"
#include <iostream>
#include <Box2D/Box2D.h>

namespace Base{
    extern int WIDTH,HEIGHT;
    extern int displayWidth, displayHeight;
    static const float M2P=20;
    static const float P2M=1/M2P;
    static b2World* world;
    int run();
    void log(std::string const &str);
    void log(double d);
    void size(int w,int h);
    void fullScreen();
}

#endif // BASE_H
