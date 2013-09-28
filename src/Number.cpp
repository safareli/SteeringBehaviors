#include <cstdlib>
#include <ctime>
#include "../include/Number.h"

bool Number::mIsSeeded = false;
Number::Number(float from,float to){
    mFrom = from;
    mTo = to;
    mIsRandom = true;
}
Number::Number(float value){
    mValue = value;
}
Number::~Number(){
    //dtor
}
float Number::getFrom(){
    return (mIsRandom)?mFrom:mValue;
}
float Number::getTo(){
    return (mIsRandom)?mTo:mValue;
}
int Number::getInt(){
    return (int) getFloat();
}
float Number::getFloat(){
    return (mIsRandom)?random(mFrom,mTo):mValue;
}
float Number::random(float from,float to){
    if (!Number::mIsSeeded ){
        Number::mIsSeeded = true;
        srand((unsigned)time(0));
    }
    return ( from + (float)rand()/((float)RAND_MAX/(to-from) ) );
}
