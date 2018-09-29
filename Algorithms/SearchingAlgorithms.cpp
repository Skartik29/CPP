#include "SearchingAlgorithms.h"

Searching::Searching()
{
    for (int i = 1; i <= 5; ++i)
        data.push_back(i);
}
Searching::~Searching()
{
    data.clear();
}
void Searching::Print()
{
    for (int i = 0; i < data.size(); ++i)
        std::cout<<data[i]<<std::endl;
}
bool Searching::BinarySearch(int key, int s, int e)
{
    if (s > e) return false;
    int mid = (s + e)/2;
    if (data[mid] == key) return true;
    else if (data[mid] > key) return BinarySearch(key, mid + 1, e);
    else return BinarySearch(key, s, mid - 1);
}
