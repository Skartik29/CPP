#include <iostream>
#include "SingletonPattern.h"

int main()
{
    Singleton *s1 = Singleton::getInstance(1);
    Singleton *s2 = s1;
    Singleton *s3 = Singleton::getInstance(2);
    //Testing if all 3 objects points to same memory by checking the value of dummy
    std::cout<<s1->getDummy()<<" "<<s2->getDummy()<<" "<<s3->getDummy()<<std::endl;

    return 0;
}
