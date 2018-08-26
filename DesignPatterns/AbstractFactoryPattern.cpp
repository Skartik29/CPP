#include "AbstractFactoryPattern.h"

Model::~Model()
{

}
LongModel::LongModel()
{
    no = 0;
    make = 0;
    boosters = 10;
}
ShortModel::ShortModel()
{
    no = 1;
    make = 1;
    wheels = 4;
}
AbstractCarFactory* AbstractCarFactory::getFactory(int factory_type, int model_type)
{
    switch(factory_type)
    {
        case 0: return new IndiaCarFactory(model_type);
        case 1: return new ForeignCarFactory(model_type);
        default: return NULL;
    }
}
AbstractCarFactory::~AbstractCarFactory()
{

}
IndiaCarFactory::IndiaCarFactory(int model_type)
{
    this->model_type = model_type;
}
Model* IndiaCarFactory::getModel()
{
    switch(model_type)
    {
        case 0: return new LongModel();
        case 1: return new ShortModel();
        default: return NULL;
    }
}
ForeignCarFactory::ForeignCarFactory(int model_type)
{
    this->model_type = model_type;
}
Model* ForeignCarFactory::getModel()
{
    switch(model_type)
    {
        case 1: return new LongModel();
        case 0: return new ShortModel();
        default: return NULL;
    }
}
AbsClient::AbsClient(int factory, int type)
{
    AbstractCarFactory* fact = AbstractCarFactory::getFactory(factory, type);
    if (factory)
        new_model = fact->getModel();
    else
        new_model = NULL;
}
void AbsClient::Interface()
{
    if (new_model)
        std::cout<<new_model->GetNo()<<" "<<new_model->GetMake()<<"\n";
    else
        std::cout<<"Absent\n";
}
AbsClient::~AbsClient()
{
    delete new_model;
}
