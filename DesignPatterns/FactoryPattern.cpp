#include "FactoryPattern.h"

Car::~Car()
{

}
LongCar::LongCar()
{
    lth = 0;
    model = 0;
    make = 0;
}
void LongCar::info()
{
    std::cout<<"long car\n";
}
BulletProof::BulletProof()
{
    proofcasing = 0;
    model = 1;
    make = 1;
}
void BulletProof::info()
{
    std::cout<<"bullet proof\n";
}
Car* Car::getCar(int type)
{
    switch(type)
    {
        case 0: return new LongCar();
        case 1: return new BulletProof();
        default: return NULL;
    }
}
Client::Client(int type)
{
    new_car = Car::getCar(type);
}
void Client::Interface()
{
    if (new_car)
        std::cout<<new_car->getModel()<<" "<<new_car->getMake()<<"\n";
    else
        std::cout<<"Absent\n";
}
Client::~Client()
{
    delete new_car;
}
