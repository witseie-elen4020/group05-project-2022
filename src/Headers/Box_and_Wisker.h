//Author: Keowa Pretorius - 1877616

//#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>

using namespace std;

#ifndef Box_and_Wisker_Class_H
#define Box_and_Wisker_Class_H

class Box_and_Wisker_Class {      
    public:  
        void sortData(vector<float> unsortedDaData);
        void computeValues();  
        void printData();
        void printGraph(); 
        vector<float> getVetor(int vecs);        
         
    private: 
        float upperWiskerValue;
        float lowerWiskerValue;
        float medianValue, Q1Value, Q3Value;
        float IQRValue, UpperBound, LowerBound;
        int DataSize;

        vector<float> sortedData;
        vector<float> lowOutliers;
        vector<float> highOutliers;
        vector<float> resultValues;

        void computeQ1();
        void computeMedian();
        void computeQ3();
        void computeBoundariesandOutliers();
        void computeWiskerBoundaries();

};

#endif