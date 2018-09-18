#include "Queue.h"

Que::Que()
{
    rear = 0;
    frnt = 0;
}
void Que::Enqueue(int data)
{
    if (rear == 100)
    {
        std::cout<<"Queue full\n";
    }
    else
    {
        storage[rear++] = data;
    }
}
void Que::Deque()
{
    if (frnt == rear)
    {
        std::cout<<"Empty queue\n";
        frnt = rear = 0;
    }
    else
    {
        std::cout<<"Dequeued item: "<<storage[frnt]<<"\n";
        frnt++;
    }
}
CQue::CQue()
{
    frnt = -1;
    rear = 0;
}
void CQue::Enqueue(int data)
{
    storage[rear%5] = data;
    if (rear >= 5)
    {
        if (frnt == -1) frnt = rear;
        else frnt++;
    }
    else
        frnt = 0;
    rear++;
}
void CQue::Deque()
{
    if (frnt == -1)
    {
        std::cout<<"Empty Queue\n";
        return;
    }
    std::cout<<"Dequeued item: "<<storage[frnt]<<"\n";
    frnt++;
    if (rear%5 == frnt%5)
    {
        frnt = -1;
        rear = 0;
    }
}
