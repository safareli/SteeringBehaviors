#ifndef ELEMENT_H
#define ELEMENT_H

#include "Color.h"
#include "PVector.h"

class Element
{
    public:
        enum Behaviors {
            MOVE_IN_A_STRAIGHT_LINE,
            CONSTRAIN_TO_SURFACE,
            CHANGE_DIRECTION_WHILE_TOUCHING_ANOTHER_ELEMENT,
            MOVE_AWAY_FROM_AN_OVERLAPPING_ELEMENT
        };
        enum Forms{
            CIRCLE
        };
        Element(int x, int y,int r,float angle,Color &c);
        Element();
        void update();
        void display(int form);
        void applyBehaviours(int* behaviours,int behaviourLength,Element* elements,int elementLength);
    protected:
    private:
        Color color;
        void applyForce(PVector force);
        float maxVelocity = 1 ,maxForce = 1, mass = 1;
        int radius;
        PVector location, velocity, acceleration;
};

#endif // ELEMENT_H
