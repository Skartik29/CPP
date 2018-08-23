#ifndef SINGLETONPATTERN_H_INCLUDED
#define SINGLETONPATTERN_H_INCLUDED

#include <iostream>

//A simple singleton class
class Singleton
{
private:
    Singleton(int v)
    {
        dummy = v;
    }
    static Singleton *instance;
    int dummy;  //Used to test the design pattern
public:
    static Singleton* getInstance(int v);
    int getDummy() const {return dummy;}
};

#endif // SINGLETONPATTERN_H_INCLUDED
