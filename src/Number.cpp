/**
 * Number.cpp
 * Date: 09/29/13
 * Author: Irakli Saparishvili
 */
#include "../include/Random.h"
#include "../include/Number.h"

Number::Number(float from,float to){
    mFrom = from;
    mTo = to;
    mIsRandom = true;
}
Number::Number(float value){
    mValue = value;
}
Number::Number(){}
Number::~Number(){}
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
    return (mIsRandom)?Random::get(mFrom,mTo):mValue;
}
