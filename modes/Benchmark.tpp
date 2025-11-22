#pragma once
#include "../core/Timer.h"
#include "../enums/PivotType.h"
#include "../core/QuickSort.h"
#include <iostream>

template<typename T>
void Benchmark::performSort() {
    initSortingType();                          //get sorting as enum
    FileManager fileManager(outputFile, numbersFileName);     //saving sorting data to files
    Randomizer randomizer;                      // Data generator
    T* array = new T[size];
    Timer timer;

    T min, max;
    if (dataType == 3){ // char
        min = 0;
        max = 255;
    } else if constexpr (std::is_integral_v<T>) {
        min = std::numeric_limits<T>::min();
        max = std::numeric_limits<T>::max();
    } else if constexpr (std::is_floating_point_v<T>) {
        min = std::numeric_limits<T>::lowest();
        max = std::numeric_limits<T>::max();
    }
    randomizer.fillArray(array,size,min,max,sortingType);   // Fill array
    std::cout<<"\nChosen sorting: "<<chosenSortingType;
    std::cout<<"\nAlgorithm\tSize\tDataType\tTime [ms]\tPivot\tCorrect?\tThreads"<<std::endl;

    PivotType pivotType;
    switch(pivot){
        case 0: pivotType = PivotType::LEFT; chosenPivot="LEFT"; break;
        case 1: pivotType = PivotType::RIGHT; chosenPivot="RIGHT"; break;
        case 2: pivotType = PivotType::MIDDLE; chosenPivot="MIDDLE"; break;
        case 3: pivotType = PivotType::RANDOM; chosenPivot="RANDOM"; break;
        default: throw std::runtime_error("Invalid algorithm type");
    }
    QuickSort<T> quickSort(array, size, pivotType, threadCount);
    timer.start();
    quickSort.sort();
    timer.stop();
    std::cout<<"Quick\t\t"<<size<<"\t"<<typeid(T).name()<<"\t"<<timer.result()
             <<"\t\t"<<chosenPivot<<"\t\t"<<quickSort.verify()<<"\t"<<threadCount<<std::endl;

    fileManager.saveData(sortingType,typeid(T).name(),size,timer.result(),chosenPivot, threadCount);
    if(numbersFileName != "-"){
        fileManager.writeFile<T>(array, size);
    }
    delete[] array;
}