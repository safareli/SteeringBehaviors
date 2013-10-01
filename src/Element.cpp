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
            case CHANGE_DIRECTION_WHILE_TOUCHING_ANOTHER_ELEMENT:{
                for(int j = 0;j < elementLength;j++){
                    Element ather = elements[j];
                    if(ather.location == location) continue;
                    PVector disired = location - ather.location;
                    if(disired.mag() <= (radius + ather.radius)){
                        PVector steer = disired - velocity;
                        steer.limit(maxForce);
                        applyForce(steer);
                    }

                }
            }

            case CONSTRAIN_TO_SURFACE:{
                int d = 20 +radius;
                PVector desired(0,0);
                if (location.x < d) {
                  desired = desired + PVector(maxVelocity, velocity.y);
                }
                else if (location.x > Base::WIDTH -d) {
                  desired = desired +  PVector(-maxVelocity, velocity.y);
                }

                if (location.y < d) {
                  desired = desired +  PVector(velocity.x, maxVelocity);
                }
                else if (location.y > Base::HEIGHT-d) {
                  desired = desired +  PVector(velocity.x, -maxVelocity);
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

    PVector a(force.x,force.y*-1);
    a.normalize();
    float degry = ((a.y < 0 )? -1 : 1) * acosf(a.x);
    arrow(location.x,location.y,radius/2,degry);

    acceleration = acceleration + (force / mass);
}

void Element::arrow(double x, double y, double r,double theta){
    GL::line(x,y,r,theta);
    GL::line(x + cosf(theta)*r,y - sinf(theta)*r, sqrt(r),theta-210);
    GL::line(x + cosf(theta)*r,y - sinf(theta)*r, sqrt(r),theta+210);
}

void Element::display(int form){
    color.regenerate();
    GL::color(color);
    switch(form){
        case CIRCLE:{
            GL::circle(location.x,location.y,radius,true);
        }
        case CIRCUMFERENCE:{
            GL::circle(location.x,location.y,radius,false);
            PVector a(velocity.x,velocity.y*-1);
            a.normalize();
            float degry = ((a.y < 0 )? -1 : 1) * acosf(a.x);
            arrow(location.x,location.y,radius,degry);
        }
        case ARROW:{
            PVector a(velocity.x,velocity.y*-1);
            a.normalize();
            float degry = ((a.y < 0 )? -1 : 1) * acosf(a.x);
            arrow(location.x,location.y,radius,degry);
        }
    }
}

