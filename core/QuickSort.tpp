
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
         quickSort(left, pivot-1);
         quickSort(pivot+1, right);
     }

//    //While loop will work for 2 iterations
//    while (left < right && left>=0) {
//        int pivot = pickPivot(left, right);
//        pivot = partition(left, right, pivot);
//
//        // Sort shorter subarray first
//        if (pivot - left < right - pivot) {
//            quickSort(left, pivot - 1);
//            left = pivot + 1;
//        } else {
//            quickSort(pivot + 1, right);
//            right = pivot - 1;
//        }
//    }
}

template <typename T>
bool QuickSort<T>::verify() {
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1])
            return false;
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