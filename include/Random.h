/**
 * Random.h
 * Date: 09/29/13
 * Author: Irakli Saparishvili
 */
 #ifndef RANDOM_H
#define RANDOM_H

#include "FractalNoise.h"

class Random
{
    public:
        static FractalNoise mPerlin;
        static float get(float from = 0,float to = 1 );
        static float noise(float from ,float to ,float x,float y = 0,float z = 0);
    protected:
    private:
        static bool mIsSeeded;
};

#endif // RANDOM_H
