#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

class Stck
{
private:
    int storage[100];
    int top;
public:
    Stck();
    void Push(int data);
    void Pop();
};

#endif // STACK_H_INCLUDED
