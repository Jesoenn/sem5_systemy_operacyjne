
#include <iostream>
#include "core/FileManager.h"
#include <random>
#include "modes/Benchmark.h"



void help(){
    std::cout<<"Usage:"<<std::endl<<"    so_projekt1.exe <dataType> <size> <sorting> <outputFile> <numbersFile> <pivot> <threads>"<<std::endl;
    std::cout<<"\t<dataType>\tData type to generate (0 - int, 1 - float, 2 - double, 3 - char)."<<std::endl;
    std::cout<<"\t<size>\t\tNumber of elements to generate (instance size)."<<std::endl;
    std::cout<<"\t<sorting>\tStarting array order (0 - Random, 1 - Ascending, 2 - Descending, 3 - 1/3 sorted, 4 - 2/3 sorted)"<<std::endl;
    std::cout<<"\t<outputFile>\tFile where the benchmark results should be saved."<<std::endl;
    std::cout<<"\t<numbersFile>\tWrites sorted array in given file. \"-\" means no file is created"<<std::endl;
    std::cout<<"\t<pivot>\t\t0 - Left, 1 - Right, 2 - Middle, 3 - Random"<<std::endl;
    std::cout<<"\t<threads>\tNumber of threads used for algorithm (>=1)"<<std::endl;
}

int main(const int argc, char* argv[]) {
    if (argc == 8) {
        const int dataType = std::stoi(argv[1]);
        const int size = std::stoi(argv[2]);
        const int sorting = std::stoi(argv[3]);
        const std::string outputFile = argv[4];
        const std::string numbersFile = argv[5];
        const int pivot = std::stoi(argv[6]);
        int threads = std::stoi(argv[7]);

        if (threads < 1){
            threads = 1;
        }

        Benchmark benchmark(dataType,size,sorting,outputFile,numbersFile,pivot, threads);
        benchmark.start();

        return 0;
    } else {
        help();
        return 1;
    }
}

