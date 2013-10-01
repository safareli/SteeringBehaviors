/**
 * Color.cpp
 * Date: 09/29/13
 * Author: Irakli Saparishvili
 */
#include "../include/Color.h"
#include "../include/Number.h"
#include "../include/Random.h"
#include <cstdlib>
//unsigned char rgba[4]
Color::Color(Number &R, Number &G ,Number &B ,Number &A){
    init(R,G,B,A);
}

Color::Color(){}
Color::Color(Number &R, Number &G ,Number &B){
    Number a(255);
    init(R,G,B,a);
}

void Color::init(Number &R, Number &G ,Number &B ,Number &A){
    g_rgba[0] = R;
    g_rgba[1] = G;
    g_rgba[2] = B;
    g_rgba[3] = A;
    regenerate();
}

void Color::setNoise(){
    setNoise(0.01f);
}
void Color::setNoise(float stepSize){
    noiseStepSize = stepSize;
    isNoise = true;

    n_rgba[0] = Random::get(1000,2000);
    n_rgba[1] = Random::get(2000,3000);
    n_rgba[2] = Random::get(3000,4000);
    n_rgba[3] = Random::get(4000,5000);
    regenerate();
}
/// Converts color to a float array
void Color::toFloat(float a[]) {
    a [0] = rgba[0]*1.0/255;
    a [1] = rgba[1]*1.0/255;
    a [2] = rgba[2]*1.0/255;
    a [3] = rgba[3]*1.0/255;
}

/// Converts color to a double array
void Color::toDouble(double a[]) {
    a [0] = rgba[0]*1.0/255;
    a [1] = rgba[1]*1.0/255;
    a [2] = rgba[2]*1.0/255;
    a [3] = rgba[3]*1.0/255;
}
int Color::get(){
    unsigned char r = rgba[0];
    unsigned char g = rgba[1];
    unsigned char b = rgba[2];
    unsigned char a = rgba[3];
    if (r > 255) r = 255; else if (r < 0) r = 0;
    if (g > 255) g = 255; else if (g < 0) g = 0;
    if (b > 255) b = 255; else if (b < 0) b = 0;
    if (a > 255) a = 255; else if (a < 0) a = 0;
    return (a << 24) | (r << 16) | (g << 8) | b;
}

 void Color::regenerate(){
    if (isNoise){
        n_rgba[0] += noiseStepSize;
        n_rgba[1] += noiseStepSize;
        n_rgba[2] += noiseStepSize;
        n_rgba[3] += noiseStepSize;
        rgba[0] = (unsigned char) Random::noise(g_rgba[0].getFrom(),g_rgba[0].getTo(), n_rgba[0]);
        rgba[1] = (unsigned char) Random::noise(g_rgba[1].getFrom(),g_rgba[1].getTo(), n_rgba[1]);
        rgba[2] = (unsigned char) Random::noise(g_rgba[2].getFrom(),g_rgba[2].getTo(), n_rgba[2]);
        rgba[3] = (unsigned char) Random::noise(g_rgba[3].getFrom(),g_rgba[3].getTo(), n_rgba[3]);

    }else{
        rgba[0] = (unsigned char) g_rgba[0].getInt();
        rgba[1] = (unsigned char) g_rgba[1].getInt();
        rgba[2] = (unsigned char) g_rgba[2].getInt();
        rgba[3] = (unsigned char) g_rgba[3].getInt();
    }
}
Color::~Color()
{
    //dtor
}
