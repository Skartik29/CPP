#include "SortingAlgorithms.h"

Sorting::Sorting()
{
    int ct = 0;
    data.push_back(5);
    data.push_back(4);
    data.push_back(5);
    data.push_back(3);
    data.push_back(1);
    data.push_back(0);
    data.push_back(2);
    data.push_back(7);
    data.push_back(6);
    data.push_back(10);
    data.push_back(8);
    data.push_back(9);
}
Sorting::~Sorting()
{
    data.clear();
}
void Sorting::Print()
{
    for (int i = 0; i < data.size(); ++i)
        std::cout<<data[i]<<std::endl;
}
void Sorting::BubbleSort()
{
    for (int i = 0; i < data.size() - 1; ++i)
        for (int j = 0; j < data.size()-i-1; ++j)
        if (data[j] > data[j + 1]) std::swap(data[j], data[j + 1]);
}
void Sorting::InsertionSort()
{
    for (int i = 1; i < data.size(); ++i)
    {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}
int Sorting::pivot(int s, int e)
{
    int pt = data[e];
    int i = s - 1;
    for (int j = s; j <= e - 1; ++j)
    {
        if (data[j] <= pt)
        {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[e]);
    return i + 1;
}
void Sorting::QuickSort(int s, int e)
{
    if (s >= e) return;
    int pt = pivot(s, e);
    QuickSort(s, pt - 1);
    QuickSort(pt + 1, e);
}
void Sorting::merging(int s, int m, int e)
{
    std::vector<int> t;
    int i = s, j = m + 1;
    while(i <= m && j <= e)
    {
        if (data[i] < data[j]) t.push_back(data[i++]);
        else t.push_back(data[j++]);
    }
    while (i <= m)
        t.push_back(data[i++]);
    while (j <= e)
        t.push_back(data[j++]);
    for (int i = 0; i < t.size(); ++i)
        data[s+i] = t[i];
}
void Sorting::MergeSort(int s, int e)
{
    if (s >= e) return;
    int mid = (s + e)/2;
    MergeSort(s, mid);
    MergeSort(mid + 1, e);
    merging(s, mid, e);
}
void Sorting::build_min_heap(int s)
{
    for (int i = data.size()/2 - 1; i >= 0; --i)
        heapify(data.size(), i);
}
void Sorting::heapify(int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && data[l] > data[largest])
        largest = l;
    if (r < n && data[r] > data[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(data[i], data[largest]);
        heapify(n, largest);
    }
}
void Sorting::HeapSort()
{
    build_min_heap(0);
    for (int i = data.size() - 1; i > 0; --i)
    {
        std::swap(data[0], data[i]);
        heapify(i, 0);
    }
}
