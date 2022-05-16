#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>
#include "omp.h"
#include "./Classes/Magnitude.cpp"
#include "./Classes/Read_File.cpp"
#include "./Classes/Box_and_Wisker.cpp"

int main(){
    //objects
    Magnitude calc1;
    Read_File file;
    Box_and_Wisker_Class Graph;

    // data variabls
    vector<float> x,y,z;
    vector<float> results;

    // time variables
    timespec realStart,realEnd;
    //timespec cpuStart,cpuEnd;
    float realT;
    omp_set_num_threads(8);
    omp_set_dynamic(1);
    
    //file.read("../Data/Accelerometer.csv");
    //file.read_dir();
	file.file_input();
    clock_gettime(CLOCK_MONOTONIC,&realStart);
    file.read_multiple();

    x = file.get_x();
	y = file.get_y();
	z = file.get_z();

    calc1.calcProcess(x,y,z);
    results = calc1.getMagnitudes();
    
    //results = {100,110,110,110,120,120,130,140,140,150,170,220};
    Graph.sortData(results);
    
    clock_gettime(CLOCK_MONOTONIC,&realEnd);
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&cpuEnd);

    realT = (1000000000 * (realEnd.tv_sec - realStart.tv_sec) + realEnd.tv_nsec - realStart.tv_nsec) * 0.000000001;
    printf("Real Total Time Process: %f seconds\n",realT);

    Graph.printData();

}
//g++ -std=c++17 -fopenmp -lgomp main.cpp -o test
//g++ -fopenmp -lgomp name.c -o name