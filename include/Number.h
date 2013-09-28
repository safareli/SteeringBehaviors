#ifndef NUMBER_H
#define NUMBER_H


class Number
{
    public:
        Number(float from,float to);
        Number(float value);
        virtual ~Number();
        float   getFrom();
        float   getTo();
        int     getInt();
        float   getFloat();
    protected:
    private:
        float random(float from = 0,float to = 1 );
        float mValue,mFrom,mTo;
        bool mIsRandom = false;
        static bool mIsSeeded;
};

#endif // NUMBER_H
