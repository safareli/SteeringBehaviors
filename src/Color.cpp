/**
 * Color.cpp
 * Date: 09/29/13
 * Author: Irakli Saparishvili
 */
#include "../include/Color.h"
#include "../include/Number.h"
#include "../include/Random.h"
#include <cstdlib>
Color::Color(Number &R, Number &G ,Number &B ,Number &A){
    init(R,G,B,A);
}

Color::Color(Number &R, Number &G ,Number &B){
    Number a(255);
    init(R,G,B,a);
}

void Color::init(Number &R, Number &G ,Number &B ,Number &A){
    mR = R;
    mG = G;
    mB = B;
    mA = A;
    regenerate();
}

void Color::setNoise(){
    setNoise(0.01f);
}
void Color::setNoise(float stepSize){
    noiseStepSize = stepSize;
    isNoise = true;
    mnR = Random::get(1000,2000);
    mnG = Random::get(2000,3000);
    mnB = Random::get(3000,4000);
    mnA = Random::get(4000,5000);
    regenerate();
}
int Color::get(){
    int r = m_R;
    int g = m_G;
    int b = m_B;
    int a = m_A;
    if (r > 255) r = 255; else if (r < 0) r = 0;
    if (g > 255) g = 255; else if (g < 0) g = 0;
    if (b > 255) b = 255; else if (b < 0) b = 0;
    if (a > 255) a = 255; else if (a < 0) a = 0;
    return (a << 24) | (r << 16) | (g << 8) | b;
}

 void Color::regenerate(){
    if (isNoise){
        mnR += noiseStepSize;
        mnG += noiseStepSize;
        mnB += noiseStepSize;
        mnA += noiseStepSize;
        m_R = (int) Random::noise(mR.getFrom(),mR.getTo(), mnR);
        m_G = (int) Random::noise(mG.getFrom(),mG.getTo(), mnG);
        m_B = (int) Random::noise(mB.getFrom(),mB.getTo(), mnB);
        m_A = (int) Random::noise(mA.getFrom(),mA.getTo(), mnA);

    }else{
        m_R = mR.getInt();
        m_G = mR.getInt();
        m_B = mR.getInt();
        m_A = mR.getInt();
    }
}
Color::~Color()
{
    //dtor
}
