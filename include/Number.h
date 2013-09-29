/**
 * Number.h
 * Date: 09/29/13
 * Author: Irakli Saparishvili
 */
 #ifndef NUMBER_H
#define NUMBER_H


class Number
{
    public:
        Number(float from,float to);
        Number(float value);
        Number();
        virtual ~Number();
        float   getFrom();
        float   getTo();
        int     getInt();
        float   getFloat();
    protected:
    private:
        float mValue,mFrom,mTo;
        bool mIsRandom = false;
};

#endif // NUMBER_H
