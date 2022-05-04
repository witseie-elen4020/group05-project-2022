#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "omp.h"
#include <vector>
#include "./Headers/Magnitude.h"


int main(){

    Magnitude calc1;
    vector<float> x,y,z;
    vector<float> results;

    for (int i = 0 ;i<10;i++){
        x.push_back(rand() % 10);
        y.push_back(rand() % 10);
        z.push_back(rand() % 10);

        cout<<"x: "<<x[i]<<", y: "<<y[i]<<", z: "<<z[i]<<"\n";
    }

    calc1.calcProcess(x,y,z);
    results = calc1.getMagnitudes();
    
    for(int i = 0;i<results.size();i++){
        cout<<results[i]<<"\n";
    }
}