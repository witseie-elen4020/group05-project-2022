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
    int realT;
    omp_set_num_threads(8);
    omp_set_dynamic(1);
    
    clock_gettime(CLOCK_MONOTONIC,&realStart);
    //file.read("../Data/Accelerometer.csv");
    //file.read_dir();
	file.file_input();
    file.read_multiple();


    x = file.get_x();
	y = file.get_y();
	z = file.get_z();

    //for(int i = 0;i<10;i++){
    //    x.push_back(rand()%10);
    //    y.push_back(rand()%10);
    //    z.push_back(rand()%10);
    //    cout<<x[i]<<"\t"<<y[i]<<"\t"<<z[i]<<"\n";
    //}

    //for(int i = 0;i<x.size();i++){
    //    cout<<x[i]<<"\t"<<y[i]<<"\t"<<z[i]<<"\n";
    //
    //}

    
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&cpuStart);

    calc1.calcProcess(x,y,z);
    results = calc1.getMagnitudes();
    cout<<results.size()<<endl;
    
    //results = file.get_mags();
    //cout<<file.get_mags().size()<<endl;
    //results = {100,110,110,110,120,120,130,140,140,150,170,220};
    Graph.sortData(results);
    //cout<<"done"<<endl;
    //#pragma omp parallel sections
    /*
    #pragma omp parallel 
    #pragma omp single
    {
        #pragma omp task
            Graph.computeQ1();
        #pragma omp task
            Graph.computeMedian();
        #pragma omp task
            Graph.computeQ3();
        #pragma omp task
            Graph.computeBoundariesandOutliers();
        #pragma omp task
            Graph.min();
        #pragma omp task
            Graph.max();

    }
    */   
    
    clock_gettime(CLOCK_MONOTONIC,&realEnd);
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&cpuEnd);

    realT = (1000000000 * (realEnd.tv_sec - realStart.tv_sec) + realEnd.tv_nsec - realStart.tv_nsec);
    //cpuT = (1000000000 * (cpuEnd.tv_sec - cpuStart.tv_sec) + cpuEnd.tv_nsec - cpuStart.tv_nsec);
    printf("Real Total Time Process: %d nano seconds\n",realT);

    
    //for(int i = 0;i<results.size();i++){
    //    cout<<results[i]<<"\n";
    //}


}
//g++ -std=c++17 -fopenmp -lgomp main.cpp -o test
//g++ -fopenmp -lgomp name.c -o name