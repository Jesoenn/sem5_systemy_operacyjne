//
// Created by jakub on 31.03.2025.
//

#include "Benchmark.h"
#include "../core/Timer.h"

Benchmark::Benchmark(int dataType, int size, int sorting, std::string outputFile, std::string numbersFile, int pivot, int threadCount):
sortingType(SortingType::NONE) {
    this->dataType = dataType;
    this->size = size;
    this->sorting = sorting;
    this->outputFile = std::move(outputFile);
    this->numbersFileName = std::move(numbersFile);
    this->pivot = pivot;
    this->chosenSortingType = "NULL";
    this->threadCount = threadCount;
}


void Benchmark::start() {
    switch (dataType) {
        case 0: {
            performSort<int>();
            break;
        }
        case 1: {
            performSort<float>();
            break;
        }
        case 2: {
            performSort<double>();
            break;
        }
        case 3: {
            performSort<char>();
            break;
        }
        default: throw std::runtime_error("Invalid type");
    }
}

void Benchmark::initSortingType() {
    switch (sorting) {
        case 0: sortingType=SortingType::NONE; chosenSortingType="RANDOM"; break;
        case 1: sortingType=SortingType::ASCENDING; chosenSortingType="ASC"; break;
        case 2: sortingType=SortingType::DESCENDING; chosenSortingType="DESC"; break;
        case 3: sortingType=SortingType::PARTIALLY_33; chosenSortingType="PART_33"; break;
        case 4: sortingType=SortingType::PARTIALLY_66; chosenSortingType="PART_66"; break;
        default: throw std::runtime_error("Invalid sorting type");
    }
}