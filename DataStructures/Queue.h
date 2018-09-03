#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

class Que
{
private:
    int storage[100];
    int rear;
    int frnt;
public:
    Que();
    void Enqueue(int data);
    void Deque();
};

class CQue
{
private:
    int storage[5];
    int rear;
    int frnt;
public:
    CQue();
    void Enqueue(int data);
    void Deque();
};

#endif // QUEUE_H_INCLUDED
