#include "SingletonPattern.h"

Singleton *Singleton::instance = NULL;

Singleton *Singleton::getInstance(int v)
{
    if (!instance)
    {
        instance = new Singleton(v);    //dummy would be set to v only once
    }
    return instance;
}
