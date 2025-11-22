
#ifndef BENCHMARK_H
#define BENCHMARK_H
#include "../core/FileManager.h"
#include "../core/Randomizer.h"



class Benchmark {
public:
    Benchmark(int dataType, int size, int sorting, std::string outputFile, std::string numbersFile, int pivot, int threadCount);
    void start();
private:
    template<typename T> void performSort();
    void initSortingType();

    int dataType,size,sorting,pivot, threadCount;
    SortingType sortingType;
    std::string outputFile,numbersFileName,chosenSortingType,chosenPivot;
};

#include "Benchmark.tpp"
#endif //BENCHMARK_H