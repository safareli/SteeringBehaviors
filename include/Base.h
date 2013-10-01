#ifndef BASE_H
#define BASE_H

#include "../include/Color.h"
#include <Box2D/Box2D.h>

namespace Base{
    static const int WIDTH=640;
    static const int HEIGHT=480;
    static const float M2P=20;
    static const float P2M=1/M2P;
    static b2World* world;
    int run();
}

#endif // BASE_H
