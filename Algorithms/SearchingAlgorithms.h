#ifndef SEARCHINGALGORITHMS_H_INCLUDED
#define SEARCHINGALGORITHMS_H_INCLUDED

#include <vector>
#include <iostream>

class Searching
{
private:
    std::vector<int> data;
public:
    Searching();
    ~Searching();
    void Print();
    bool BinarySearch(int key, int s, int e);
    int GetSize() const {return data.size();}
};

#endif // SEARCHINGALGORITHMS_H_INCLUDED
