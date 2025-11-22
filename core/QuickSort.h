
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "../enums/PivotType.h"
#include <random>
#include <atomic>

template <typename T>
class QuickSort {
public:
    QuickSort(T* array, int size, PivotType pivotT, int maxThreads);
    void sort(); //left/right are indexes
    bool verify();
private:
    void quickSort(int left, int right);
    int partition(int left, int right, int pivot);
    int pickPivot(int left, int right);

    PivotType pivotType;
    T* array;
    int size;
    std::random_device rd;
    std::mt19937 gen;
    std::atomic<int> threadCount;
    int maxThreads;
};

#include "QuickSort.tpp"
#endif //QUICKSORT_H