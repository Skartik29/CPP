#include "Stack.h"

Stck::Stck()
{
    top = -1;
}
void Stck::Push(int data)
{
    if (top == 99)
    {
        std::cout<<"Stack overflow\n";
    }
    else
        storage[++top] = data;
}
void Stck::Pop()
{
    if (top == -1)
    {
        std::cout<<"Empty stack\n";
    }
    else
    {
        std::cout<<"Popped item: "<<storage[top]<<"\n";
        top--;
    }
}
