#ifndef FACTORYPATTERN_H_INCLUDED
#define FACTORYPATTERN_H_INCLUDED

#include <iostream>

class Car
{
protected:
    int model;
    int make;
public:
    static Car* getCar(int type);
    int getModel() const {return model;}
    int getMake() const {return make;}
    virtual void info() = 0;
    virtual ~Car();
};
class LongCar:public Car
{
protected:
    int lth;
public:
    LongCar();
    void info();
};
class BulletProof:public Car
{
protected:
    int proofcasing;
public:
    BulletProof();
    void info();
};
class Client
{
private:
    Car *new_car;
    Client(const Client&);
    Client& operator=(const Client&);
public:
    Client(int type);
    void Interface();
    ~Client();
};

#endif // FACTORYPATTERN_H_INCLUDED
