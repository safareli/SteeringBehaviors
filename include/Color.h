/**
 * Color.h
 * Date: 09/29/13
 * Author: Irakli Saparishvili
 */
#ifndef COLOR_H
#define COLOR_H

#include "Number.h"


class Color
{
    public:
        Color(Number &R, Number &G ,Number &B ,Number &A) ;
        Color(Number &R, Number &G ,Number &B);
        void setNoise();
        void setNoise(float stepSize);
        void regenerate();
        int get();
        virtual ~Color();
    protected:
    private:
        void init(Number &R, Number &G ,Number &B ,Number &A);
        Number mR,mG,mB,mA;//generators
        int m_R,m_G,m_B,m_A; //generated int values
        float mnR,mnG,mnB,mnA; //noise steps
        bool isNoise = false;
        float noiseStepSize;
};

#endif // COLOR_H
