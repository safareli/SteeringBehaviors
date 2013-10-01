#include <iostream>
#include "../include/gl.h"
#include "../include/Base.h"
#include "../include/Color.h"
#include "../include/Element.h"
#include "../include/PVector.h"
#include "../include/Number.h"

Element::Element(int x, int y,int r,float angle,Color &c){
    radius = r;
    location = PVector(x,y);
    velocity = PVector(cos(angle),sin(angle));
    velocity = velocity * 3;
    acceleration = PVector(0,0);
    color = c;
}
Element::Element(){}
void Element::applyBehaviours(int* behaviours,int behaviourLength,Element* elements,int elementLength){
    for(int i = 0; i < behaviourLength; i++){
        switch(behaviours[i]){
            case CHANGE_DIRECTION_WHILE_TOUCHING_ANOTHER_ELEMENT:
            break;

            case CONSTRAIN_TO_SURFACE:{
                int d = 20;
                PVector desired(0,0);
                if (location.x < d) {
                  desired = PVector(maxVelocity, velocity.y);
                }
                else if (location.x > Base::WIDTH -d) {
                  desired = PVector(-maxVelocity, velocity.y);
                }

                if (location.y < d) {
                  desired = PVector(velocity.x, maxVelocity);
                }
                else if (location.y > Base::HEIGHT-d) {
                  desired = PVector(velocity.x, -maxVelocity);
                }

                if (desired.mag() != 0) {
                  desired.normalize();
                  desired = desired * maxVelocity;
                  PVector steer = desired - velocity;
                  steer.limit(maxForce);
                  applyForce(steer);
                }
            }

            case MOVE_AWAY_FROM_AN_OVERLAPPING_ELEMENT:
            break;

            case MOVE_IN_A_STRAIGHT_LINE:
            break;
        }
    }
}

// update Elements location
void Element::update(){
    // add acceleration to velocity
    velocity  = velocity + acceleration;
    // limit velocity using maxVelocity
    velocity.limit(maxVelocity);
    // add velocity to location
    location = location + velocity;
    // clear acceleration
    acceleration = acceleration * 0;
}

//apply force to Thing
void Element::applyForce(PVector force) {
    // force = mass * acceleration
    // acceleration = force / mass
    acceleration = acceleration + (force / mass);
}


void Element::display(int form){
    color.regenerate();
    GL::color(color);
    switch(form){
        case CIRCLE:
            GL::circle(location.x,location.y,radius);
        break;
    }
}

