
#include "FileManager.h"
#include <utility>
#include <iostream>
#include <fstream>

FileManager::FileManager(std::string fileName, std::string outputFileName)
    : outputFileName(std::move(outputFileName)), dataFileName(std::move(fileName)) {}


void FileManager::saveData(const SortingType sorting, const std::string& variable, const int elements,
    const int time, const std::string& pivot, int threads) const {
    std::ofstream file(dataFileName, std::ios::app);

    if (!file.is_open()) {
        std::cout << "Cannot open/create data file." << std::endl;
        return;
    }
    //Rodzaj algorytmu | Poczatkowe sortowanie | Typ zmiennej | Liczba elementow | Średni czas ms | watki
    file
    << pivot << "\t"
    << toString(sorting) << "\t"
    << variable << "\t"
    << elements << "\t"
    << time << "\t"
    << threads << std::endl;

    file.close();
}

std::string FileManager::toString(const SortingType sorting) {
    switch (sorting) {
        case SortingType::NONE: return "NONE";
        case SortingType::ASCENDING: return "ASCENDING";
        case SortingType::DESCENDING: return "DESCENDING";
        case SortingType::PARTIALLY_33 : return "PARTIALLY_33";
        case SortingType::PARTIALLY_66 : return "PARTIALLY_66";
        default: return "ERROR";
    }
}