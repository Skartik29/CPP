#include <iostream>
#include "SingletonPattern.h"
#include "FactoryPattern.h"
#include "AbstractFactoryPattern.h"

int main()
{
    /** Test: Singleton Pattern **/
    Singleton *s1 = Singleton::getInstance(1);
    Singleton *s2 = s1;
    Singleton *s3 = Singleton::getInstance(2);
    //Testing if all 3 objects points to same memory by checking the value of dummy
    //std::cout<<s1->getDummy()<<" "<<s2->getDummy()<<" "<<s3->getDummy()<<std::endl;
    /** Test: Factory Pattern **/
    Client *c1 = new Client(0);
    Client *c2 = new Client(1);
    Client *c3 = new Client(100);
    //c1 = c2;  //Disabled copy constructor still why copying ?
    //c1->Interface();
    //c2->Interface();
    //c3->Interface();
    AbsClient *a1 = new AbsClient(0,0);
    AbsClient *a2 = new AbsClient(1,1);
    AbsClient *a3 = new AbsClient(100,100);
    a1->Interface();
    a2->Interface();
    a3->Interface();

    return 0;
}
