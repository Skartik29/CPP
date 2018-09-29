#ifndef SORTINGALGORITHMS_H_INCLUDED
#define SORTINGALGORITHMS_H_INCLUDED

#include <iostream>
#include <vector>

class Sorting
{
private:
    std::vector<int> data;
    int pivot(int s, int e);
    void merging(int s, int m, int e);
    void build_min_heap(int s);
    void heapify(int n, int i);
public:
    Sorting();
    ~Sorting();
    void BubbleSort();
    void InsertionSort();
    void QuickSort(int s, int e);
    void MergeSort(int s, int e);
    void HeapSort();
    void Print();
    int GetSize() const {return data.size();}
};

#endif // SORTINGALGORITHMS_H_INCLUDED
