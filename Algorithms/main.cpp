#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"

using namespace std;


//insertion sort, bubble sort, merge sort, quick sort, heap sort, binary search
int main()
{
    Sorting* ss = new Sorting();
    //ss->Print();
    ss->BubbleSort();
    ss->InsertionSort();
    ss->QuickSort(0, ss->GetSize() - 1);
    ss->MergeSort(0, ss->GetSize() - 1);
    ss->HeapSort();
    //ss->Print();
    delete ss;

    Searching* sh = new Searching();
    //std::cout<<sh->BinarySearch(10, 0, sh->GetSize() - 1)<<std::endl;
    delete sh;

    return 0;
}
