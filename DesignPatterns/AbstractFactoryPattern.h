#ifndef ABSTRACTFACTORYPATTERN_H_INCLUDED
#define ABSTRACTFACTORYPATTERN_H_INCLUDED

#include "iostream"

class Model
{
protected:
    int no;
    int make;
public:
    int GetNo() const {return no;}
    int GetMake() const {return make;}
    virtual ~Model() = 0;
};
class LongModel:public Model
{
private:
    int boosters;
public:
    LongModel();
};
class ShortModel:public Model
{
private:
    int wheels;
public:
    ShortModel();
};
class AbstractCarFactory
{
protected:
    int model_type;
public:
    static AbstractCarFactory* getFactory(int factory_type, int model_type);
    virtual Model* getModel() = 0;
    virtual ~AbstractCarFactory() = 0;
};
class IndiaCarFactory:public AbstractCarFactory
{
public:
    IndiaCarFactory(int model_type);
    Model* getModel();
};
class ForeignCarFactory:public AbstractCarFactory
{
public:
    ForeignCarFactory(int model_type);
    Model* getModel();
};
class AbsClient
{
private:
    Model* new_model;
public:
    AbsClient(int factory, int type);
    void Interface();
    ~AbsClient();
};

#endif // ABSTRACTFACTORYPATTERN_H_INCLUDED
