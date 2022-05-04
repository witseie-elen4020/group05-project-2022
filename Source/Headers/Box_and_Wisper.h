//Author: Keowa Pretorius - 1877616
#ifndef Box_and_Wisker_Class_H
#define Box_and_Wisker_Class_H

#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>

class Box_and_Wisker_Class {      
    public:  
        void sortData(vector<float> unsortedDaData);
        void computeValues();  
        void printData();         
         
    private: 
        float upperWiskerValue = 0.0;
        float lowerWiskerValue = 0.0;
        float medianValue, Q1Value, Q3Value;
        float IQRValue, UpperBound, LowerBound;
        int DataSize = 0;

        vector<float> sortedData;
        vector<float> lowOutliers;
        vector<float> highOutliers;

        void computeQ1();
        void computeMedian();
        void computeQ3();
        void computeBoundariesandOutliers();
        void computeWiskerBoundaries();

};

#endif