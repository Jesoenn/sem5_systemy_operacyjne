
#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include "../enums/SortingType.h"


class FileManager {
public:
    FileManager(std::string fileName, std::string outputFileName);
    template<typename T> void writeFile(T* array, int arraySize); //For file test mode
    void saveData(SortingType sorting, const std::string& variable, int elements, int time, const std::string& pivot, int threads) const;

    static std::string toString(SortingType sorting);

private:
    const std::string outputFileName,dataFileName;
};

#include "FileManager.tpp"
#endif //FILEMANAGER_H