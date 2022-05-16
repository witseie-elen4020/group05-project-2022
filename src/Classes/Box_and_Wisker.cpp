//Author: Keowa Pretorius - 1877616
//Compile using:    g++ -std=c++11 Box_and_Wisker.cpp -o Projexe
//Run using:        ./Projexe
#include "../Headers/Box_and_Wisker.h"

//#include <syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>

using namespace std;

void Box_and_Wisker_Class::sortData(vector<float> unsortedDaData) {
    sortedData = unsortedDaData;
    sort(sortedData.begin(), sortedData.end()); //Sort data in ascending order

    DataSize = sortedData.size();
    lowerWiskerValue = sortedData.at(0);
    upperWiskerValue = sortedData.at(DataSize - 1);

    computeQ1();
    computeMedian();
    computeQ3();
    computeBoundariesandOutliers();
}

void Box_and_Wisker_Class::printData() {
    cout << "VecSize = " << DataSize  << endl;
    cout << "Lower wisker = " << lowerWiskerValue << " Q1 = " << Q1Value << " Q2 = " << medianValue << " Q3 = " << Q3Value << " Upper wisker = " << upperWiskerValue <<" IQRValue = "<< IQRValue << endl;
/*
    cout << "Lower outliers:" << endl;
    for(auto& element : lowOutliers){
        cout << element << "  ";
    }
    cout << endl;
    cout << "Higher outliers:" << endl;
    for(auto& element : highOutliers){
        cout << element << "  ";
    }
    cout << endl;
*/
}

void Box_and_Wisker_Class::computeQ1() {
    if(DataSize/2 % 2 == 0){   //Vector size is even
        Q1Value = (sortedData.at(DataSize/4 - 1) + sortedData.at(DataSize/4))/2;
        Q1Index = (DataSize/4) + 1;
    }else { //Vector size is odd
        Q1Value = sortedData.at(DataSize/4);
        Q1Index = (DataSize/4);
    }
}

void Box_and_Wisker_Class::computeMedian() {
    if(DataSize % 2 == 0){   //Vector size is even
        medianValue = (sortedData.at(DataSize/2 - 1) + sortedData.at(DataSize/2))/2;
    }else { //Vector size is odd
        medianValue = sortedData.at((DataSize/2));
    }
}

void Box_and_Wisker_Class::computeQ3() {
    if(DataSize/2 % 2 == 0){   //Vector size is even
        Q3Value = (sortedData.at(DataSize - (DataSize/4) - 1) + sortedData.at(DataSize - (DataSize/4)))/2;
        Q3Index = (DataSize - (DataSize/4)) -1;
    }else { //Vector size is odd
        Q3Value = sortedData.at(3*DataSize/4);
        Q3Index = 3*DataSize/4;
    }
}

void Box_and_Wisker_Class::computeBoundariesandOutliers() {
    IQRValue = Q3Value - Q1Value;
    LowerBound = Q1Value - 1.5*IQRValue;
    UpperBound = Q3Value + 1.5*IQRValue;
    
    //Use threads to find outliers
    #pragma omp parallel for schedule (static) firstprivate(sortedData)
    for(auto& element : sortedData){
        if(element < LowerBound){   //Find outliers below IQR boundary
            #pragma omp critical
            lowOutliers.push_back(element);
        }
        if(element > UpperBound){   //Find outliers above IQR boundary
            #pragma omp critical
            highOutliers.push_back(element);
        }
    }
    //Find lower wisker value by excluding outliers from sorted data vector to get first remaining value
    lowerWiskerValue = sortedData[lowOutliers.size()];
    //Find upper wisker value by excluding outliers from sorted data vector to get last remaining value
    upperWiskerValue = sortedData[sortedData.size()-highOutliers.size()-1];
}
