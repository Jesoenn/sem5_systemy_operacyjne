#include <thread>
#pragma once

template<typename T>
QuickSort<T>::QuickSort(T *array, int size, PivotType pivotT, int maxThreads):
    gen(rd()), size(size), pivotType(pivotT), threadCount(1), maxThreads(maxThreads){
    this->array = array;
}

template<typename T>
void QuickSort<T>::sort() {
    quickSort(0, size-1);
}

template<typename T>
int QuickSort<T>::partition(int left, int right, int pivot) {
    int j = left;                                       //index where elements smaller or equal pivot are placed
    std::swap(array[pivot], array[right]);    //move pivot to right
    pivot = right;

    for (int i = left; i < right; i++) {                //for each element from min index to max index
        if (array[i] <= array[pivot]) {
            std::swap(array[i], array[j]);    //place arr[i] on j place (swap)
            j++;                                        //move swap index to next place
        }
    }
    std::swap(array[j], array[pivot]);        //move pivot to swap index
    return j;
}

template<typename T>
void QuickSort<T>::quickSort(int left, int right) {
     if (left < right && left>=0) {
         int pivot = pickPivot(left, right);
         pivot = partition(left, right, pivot);

         std::thread thread;
         bool threadCreated = false;

         int leftSize  = pivot - left;
         int rightSize = right - pivot;

         if(threadCount < maxThreads){
             threadCount++;
             threadCreated = true;
             if(rightSize > leftSize){
                 thread = std::thread(&QuickSort<T>::quickSort, this, pivot+1, right);
                 quickSort(left, pivot-1); // Smaller array in main thread
             } else {
                 thread = std::thread(&QuickSort<T>::quickSort, this, left, pivot-1);
                 quickSort(pivot+1, right); // Smaller array in main thread
             }
         } else {
             quickSort(left, pivot-1);
             quickSort(pivot+1, right);
         }

//         // Multithreading
//         if( threadCount < maxThreads ){
//             threadCount++;
//             threadCreated = true;
//             thread = std::thread(&QuickSort<T>::quickSort, this, pivot+1, right);
//         } else {
//             quickSort(pivot+1, right);
//         }
//         quickSort(left, pivot-1);

         if(threadCreated)
             thread.join();
     }
}

template <typename T>
bool QuickSort<T>::verify() {
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]){
            std::cout<<"\n\nBLAD SORTOWANIA\n\n";
            system("PAUSE");
            return false;
        }
    }
    return true;
}

template <typename T>
int QuickSort<T>::pickPivot(const int left, const int right) {
    switch (pivotType) {
        case PivotType::LEFT: return left;
        case PivotType::RIGHT: return right;
        case PivotType::MIDDLE: return left + (right - left) / 2;
        case PivotType::RANDOM: {
            std::uniform_int_distribution<int> dist(left, right);
            return dist(gen);
        }
        default: throw std::runtime_error("Invalid pivot type in pickPivot()");
    }
}