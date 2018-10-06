#include "Puzzles.h"

ArrayPuzzles::ArrayPuzzles()
{
    arr[0] = 1;
    arr[1] = 10;
    arr[2] = 9;
    arr[3] = 3;
    arr[4] = 2;
    arr[5] = 5;
    arr[6] = 4;
    arr[7] = 2;
    arr[8] = 3;
    arr[9] = 7;
}
void ArrayPuzzles::PrintArray()
{
    for (int i = 0; i < 10; ++i)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}
void ArrayPuzzles::Reverse()
{
    int left = 0;
    int right = 9;
    while (left < right)
    {
        std::swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
bool ArrayPuzzles::IsPalindrome()
{
    int left = 0;
    int right = 9;
    while (left < right)
    {
        if (arr[left] != arr[right]) return false;
        left++;
        right--;
    }
    return true;
}
void ArrayPuzzles::Push(int ind)
{
    int t = arr[ind];
    int current = ind;
    int previous = current - 1;
    if (previous == -1) previous = 9;
    int stop = ind + 1;
    if (stop == 10) stop = 0;
    while (current != stop)
    {
        arr[current] = arr[previous];
        current--;
        if (current == -1) current = 9;
        previous--;
        if (previous == -1) previous = 9;
    }
    arr[stop] = t;
}
void ArrayPuzzles::Pull(int ind)
{
    int t = arr[ind];
    int current = ind;
    int after = current + 1;
    if (after == 10) after = 0;
    int stop = ind - 1;
    if (stop == -1) stop = 9;
    while (current != stop)
    {
        arr[current] = arr[after];
        current++;
        if (current == 10) current = 0;
        after++;
        if (after == 10) after = 0;
    }
    arr[stop] = t;
}
void ArrayPuzzles::ClockwiseRotation(int pos)
{
    if (pos <= 0 || pos > 9) return;
    int ct = 9 - pos + 1;
    for (int i = 0; i < ct; ++i)
    {
        Push(pos + i);
    }
}
void ArrayPuzzles::AnticlockwiseRotation(int pos)
{
    if (pos < 0 || pos >= 9) return;
    int ct = pos + 1;
    for (int i = 0; i < ct; ++i)
    {
        Pull(pos + i);
    }
}
