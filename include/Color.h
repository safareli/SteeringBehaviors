/**
 * Color.h
 * Date: 10/01/13
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
        Color();
        void toDouble(double a[]);
        void toFloat(float a[]);
        void setNoise();
        void setNoise(float stepSize);
        void regenerate();
        unsigned char rgba[4];
        int get();
        virtual ~Color();
    protected:
    private:
        void init(Number &R, Number &G ,Number &B ,Number &A);
        Number g_rgba[4];
        float n_rgba[4];
        bool isNoise = false;
        float noiseStepSize;
};

#endif // COLOR_H
