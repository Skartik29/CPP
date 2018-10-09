#ifndef PUZZLES_H_INCLUDED
#define PUZZLES_H_INCLUDED

#include <iostream>
#include <stack>
#include <queue>
#include "Stack.h"
#include "Queue.h"

class ArrayPuzzles
{
private:
    Stck* sstck;
    Que* qque;
    int arr[10];
    int twoDArr[5][5];
    void Push(int ind);
    void Push2D(int pos, int row);
    void Pull(int ind);
    bool IsPalind2D(int ind, bool rowOrCol);
    void Decrement2D(int& row, int& col, int r);
    void Increment2D(int& row, int& col, int r);
    void RotateRow(int row);
public:
    ArrayPuzzles();
    void PrintArray();
    void Print2DArray();
    void Reverse();
    bool IsPalindrome();
    bool Is2DPalindrome();
    void ClockwiseRotation(int pos);
    void AnticlockwiseRotation(int pos);
    void Rotate90DegreeClockwise();
};

class QueueUsingStacks
{
private:
    std::stack<int> s1, s2;
    int curr;
    bool state;
public:
    QueueUsingStacks();
    void Enqueue(int item);
    int Dequeue();
};

class StackUsingQueues
{
private:
    std::queue<int> q1, q2;
    int curr;
public:
    StackUsingQueues();
    void Push(int item);
    int Pop();
};

#endif // PUZZLES_H_INCLUDED
