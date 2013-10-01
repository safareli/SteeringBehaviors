#include <iostream>
#include "../include/Number.h"
#include "../include/Color.h"
#include "../include/Base.h"
#include "../include/gl.h"
#include <ctime>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Box2D/Box2D.h>

using namespace Base;
Number n(0,255);
Color mcolor(n,n,n);

void setup(){
    mcolor.setNoise(0.001f);
    world = new b2World(b2Vec2(0.0,9.81));
}

void draw(){
    mcolor.regenerate();
    GL::background(mcolor);
}

int main(){
    return run();
}
