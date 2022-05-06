#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "omp.h"
#include "./Headers/Magnitude.h"
#include "./Headers/Read_File.h"
#include "./Headers/Box_and_Wisker.h"

int main(){

    Magnitude calc1;
    vector<float> x,y,z;
    vector<float> results;
    timespec realStart,realEnd;
    timespec cpuStart,cpuEnd;
    int realT,cpuT;
    
    omp_set_num_threads(8);

    #pragma omp parralel for
        for (int i = 0 ;i<1000000;i++){
            x.push_back(rand() % 10);
            y.push_back(rand() % 10);
            z.push_back(rand() % 10);

            //cout<<"x: "<<x[i]<<", y: "<<y[i]<<", z: "<<z[i]<<"\n";
        }
    clock_gettime(CLOCK_MONOTONIC,&realStart);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&cpuStart);

    calc1.calcProcess(x,y,z);

    clock_gettime(CLOCK_MONOTONIC,&realEnd);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&cpuEnd);

    realT = (1000000000 * (realEnd.tv_sec - realStart.tv_sec) + realEnd.tv_nsec - realStart.tv_nsec);
    cpuT = (1000000000 * (cpuEnd.tv_sec - cpuStart.tv_sec) + cpuEnd.tv_nsec - cpuStart.tv_nsec);
    printf("CPU Time process: %d nano seconds \nReal Time Process: %d nano seconds\n",cpuT,realT);
    results = calc1.getMagnitudes();
    
    //for(int i = 0;i<results.size();i++){
    //    cout<<results[i]<<"\n";
    //}
}

//g++ -fopenmp -lgomp name.c -o name