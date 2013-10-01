#include <iostream>
#include "../include/Number.h"
#include "../include/Color.h"
#include "../include/Base.h"
#include "../include/Element.h"
#include "../include/gl.h"
#include <ctime>
#include <Box2D/Box2D.h>

using namespace Base;
Color backgroundColor;
int elementLength = 10000;
Element* elements = new Element[elementLength];

int behaviourLength = 4;
int behaviours[] = {
    Element::MOVE_IN_A_STRAIGHT_LINE,
    Element::CONSTRAIN_TO_SURFACE,
    Element::CHANGE_DIRECTION_WHILE_TOUCHING_ANOTHER_ELEMENT,
    Element::MOVE_AWAY_FROM_AN_OVERLAPPING_ELEMENT
};

//bool isFullScreen(){ return true;}

void setup(){
    //size(640,400);
    size(displayWidth,displayHeight);
    Number n(0,255);
    backgroundColor = Color(n,n,n);
    backgroundColor.setNoise(0.001f);
    world = new b2World(b2Vec2(0.0,9.81));
    Number  x(0,WIDTH),
            y(0,HEIGHT),
            radius(5,20),
            angle(0,360),
            r(100,255),
            g(50,150),
            b(0);
    for(int i = 0; i<elementLength; i++){
        Color elementColor(r,g,b);
        elementColor.setNoise(0.01f);
        elements[i] = Element(
                          x.getInt(),
                          y.getInt(),
                          radius.getInt(),
                          angle.getFloat(),
                          elementColor
                    );
    }
}

void draw(){

    backgroundColor.regenerate();
    GL::background(backgroundColor);
    for(int i = 0; i<elementLength; i++){
        elements[i].applyBehaviours(behaviours,behaviourLength,elements,elementLength);
        elements[i].update();
        elements[i].display(Element::CIRCLE);
    }

}

int main(){
    return run();
}
