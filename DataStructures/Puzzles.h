#ifndef PUZZLES_H_INCLUDED
#define PUZZLES_H_INCLUDED

#include <iostream>

class ArrayPuzzles
{
private:
    int arr[10];
    void Push(int ind);
    void Pull(int ind);
public:
    ArrayPuzzles();
    void PrintArray();
    void Reverse();
    bool IsPalindrome();
    void ClockwiseRotation(int pos);
    void AnticlockwiseRotation(int pos);
};

#endif // PUZZLES_H_INCLUDED
