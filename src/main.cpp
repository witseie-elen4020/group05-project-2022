#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
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
    timespec cpuStart,cpuEnd;
    int realT,cpuT;
    
    omp_set_num_threads(8);

    file.read("../Data/Accelerometer.csv");
	

    x = file.get_x();
	y = file.get_y();
	z = file.get_z();

    //for(int i = 0;i<x.size();i++){
    //    cout<<x[i]<<"\t"<<y[i]<<"\t"<<z[i]<<"\n";
    //
    //}

    clock_gettime(CLOCK_MONOTONIC,&realStart);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&cpuStart);

    calc1.calcProcess(x,y,z);
    results = calc1.getMagnitudes();
    
    Graph.sortData(results);
    Graph.printData();    
    
    clock_gettime(CLOCK_MONOTONIC,&realEnd);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&cpuEnd);

    realT = (1000000000 * (realEnd.tv_sec - realStart.tv_sec) + realEnd.tv_nsec - realStart.tv_nsec);
    cpuT = (1000000000 * (cpuEnd.tv_sec - cpuStart.tv_sec) + cpuEnd.tv_nsec - cpuStart.tv_nsec);
    printf("CPU Time process: %d nano seconds \nReal Time Process: %d nano seconds\n",cpuT,realT);

    
    //for(int i = 0;i<results.size();i++){
    //    cout<<results[i]<<"\n";
    //}


}

//g++ -fopenmp -lgomp name.c -o name