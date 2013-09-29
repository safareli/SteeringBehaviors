/**
 * Random.cpp
 * Date: 09/29/13
 * Author: Irakli Saparishvili
 */
#include "../include/Random.h"
#include "../include/FractalNoise.h"
#include <cstdlib>
#include <ctime>

FractalNoise Random::mPerlin = FractalNoise();
bool Random::mIsSeeded = false;
float Random::get(float from,float to){
    if (!Random::mIsSeeded ){
        Random::mIsSeeded = true;
        srand(time(0));
        rand();
    }
    return ( from + (float)rand()/((float)RAND_MAX/(to-from) ) );
}
float Random::noise(float from ,float to ,float x, float y , float z){
    return from + (Random::mPerlin.noise(x,y,z)+ 0.5f )*(to - from);
}
