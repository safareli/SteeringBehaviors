#include <iostream>
#include "../include/Number.h"
#include "../include/Random.h"
#include "../include/Color.h"
#include "../include/PVector.h"
#include <ctime>

using namespace std;

int main(){
    Number mRandR(100,200);
    Number mRandG(10,255);
    Number mRandB(0,10);
    Number mRandA(255);
    PVector vec1(10,5);
    PVector vec2(-5,5);
    Color mColor(mRandR,mRandG,mRandB,mRandA);
    mColor.setNoise(0.01);
    mColor.regenerate();
    PVector v = vec1 + vec2;
    std::cout << mColor.get() << "\n";
    std::cout << v.x << "\n";
    std::cout << v.y << "\n";
    std::cout << v.z << "\n";

    /*float max=0,min=0;
    for(float i = 0; i <10 ; i +=0.01){
        float noise = Random::noise(0,1,i);
        max = (noise > max )? noise : max;
        min = (noise < min) ? noise : min;
    }
    std::cout << "min|max|"<<min<<"|"<<max<< "\n";*/
    return 0;
}
