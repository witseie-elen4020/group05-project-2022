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
    sort(sortedData.begin(), sortedData.end());

    DataSize = sortedData.size();
    lowerWiskerValue = sortedData.at(0);
    upperWiskerValue = sortedData.at(DataSize - 1);

    computeValues();
}

void Box_and_Wisker_Class::computeValues() {
    computeQ1();
    computeMedian();
    computeQ3();
    computeBoundariesandOutliers();
}

void Box_and_Wisker_Class::printData() {
    //cout << "Sorted vector of magnitudes is:" << endl;
    //for(auto& element : sortedData){
    //    cout << element << "  ";
    //}
    //cout << endl;
    cout << "VecSize = " << DataSize  << endl;
    cout << "Lower wisker = " << lowerWiskerValue << " Q1 = " << Q1Value << " Q2 = " << medianValue << " Q3 = " << Q3Value << " Upper wisker = " << upperWiskerValue <<" IQRValue = "<< IQRValue << endl;

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
}

void Box_and_Wisker_Class::printGraph() {
    //Still in progress
    resultValues.push_back(lowerWiskerValue);
    resultValues.push_back(Q1Value);
    resultValues.push_back(medianValue);
    resultValues.push_back(Q3Value);
    resultValues.push_back(upperWiskerValue);

}

vector<float> Box_and_Wisker_Class::getVetor(int vecs) {
    resultValues.push_back(lowerWiskerValue);
    resultValues.push_back(Q1Value);
    resultValues.push_back(medianValue);
    resultValues.push_back(Q3Value);
    resultValues.push_back(upperWiskerValue);

    if(vecs == 0){
        return resultValues;
    } else if(vecs == 1) {
        return lowOutliers;
    } else if(vecs == 2) {
        return highOutliers;
    } else {
        return sortedData;
    }
}

void Box_and_Wisker_Class::computeQ1() {
    if(DataSize/2 % 2 == 0){   //Vector size is even
        Q1Value = (sortedData.at(DataSize/4 - 1) + sortedData.at(DataSize/4))/2;
        Q1Index = (DataSize/4) + 1;
    }else { //Vector size is odd
        Q1Value = sortedData.at(DataSize/4);
        Q1Index = (DataSize/4);
    }
    //cout<<"Q1: "<<Q1Value<<endl;
}

void Box_and_Wisker_Class::computeMedian() {
    if(DataSize % 2 == 0){   //Vector size is even
        medianValue = (sortedData.at(DataSize/2 - 1) + sortedData.at(DataSize/2))/2;
    }else { //Vector size is odd
        medianValue = sortedData.at((DataSize/2));
    }
    //cout<<"Median: "<<medianValue<<endl;
}

void Box_and_Wisker_Class::computeQ3() {
    if(DataSize/2 % 2 == 0){   //Vector size is even
        Q3Value = (sortedData.at(DataSize - (DataSize/4) - 1) + sortedData.at(DataSize - (DataSize/4)))/2;
        Q3Index = (DataSize - (DataSize/4)) -1;
    }else { //Vector size is odd
        Q3Value = sortedData.at(3*DataSize/4);
        Q3Index = 3*DataSize/4;
    }
    //cout<<"Q3: "<<Q3Value<<endl;
}

void Box_and_Wisker_Class::computeBoundariesandOutliers() {
    IQRValue = Q3Value - Q1Value;
    LowerBound = Q1Value - 1.5*IQRValue;
    UpperBound = Q3Value + 1.5*IQRValue;
    //cout<<"Lower Bound: "<<LowerBound<<endl;
    //cout<<"IQR Value: "<<IQRValue<<endl;
    //cout<<"Upper Bound: "<<UpperBound<<endl;
    #pragma omp parallel for schedule (static) firstprivate(sortedData)
    for(auto& element : sortedData){
        if(element < LowerBound){
            #pragma omp critical
            lowOutliers.push_back(element);
        }
        if(element > UpperBound){
            #pragma omp critical
            highOutliers.push_back(element);
        }
    }
    
    //sort(lowOutliers.begin(), lowOutliers.end());
    //sort(highOutliers.begin(), highOutliers.end());

    timespec realStart,realEnd;
    int realT;
    clock_gettime(CLOCK_MONOTONIC,&realStart);
    computeWiskerBoundaries();
    clock_gettime(CLOCK_MONOTONIC,&realEnd);
    realT = (1000000000 * (realEnd.tv_sec - realStart.tv_sec) + realEnd.tv_nsec - realStart.tv_nsec);
    printf("Real Time Whisker Process: %d nano seconds\n",realT);
}

void Box_and_Wisker_Class::computeWiskerBoundaries() {
    bool LowerFound = false; 
    bool upperFound = false;

    #pragma omp parallel for schedule(static) firstprivate(sortedData)
    for(int i = 0;i<=Q1Index;i++){
        if(LowerFound){continue;}
        if(sortedData[i]>= LowerBound){
                lowerWiskerValue = sortedData[i];
                LowerFound = true;
            }
    }
    //cout<<"Lower Whisker: "<<lowerWiskerValue<<endl;

    #pragma omp parallel for schedule(static) firstprivate(sortedData)
    for(int i = sortedData.size() -1 ;i>=Q3Index;i--){
        if(upperFound){continue;}
        if(sortedData[i]<=UpperBound){
                upperWiskerValue=sortedData[i];
                upperFound = true;
            }
    }
   // cout<<"Upper Whisker: "<<upperWiskerValue<<endl;


    //for(auto& elementParent : sortedData){
    //    //Lower wisker
    //    if(!LowerFound){
    //        for(auto& elementLowerB : lowOutliers){
    //            if(elementParent >= LowerBound && elementParent != elementLowerB){
    //                lowerWiskerValue = elementParent;
    //                LowerFound = true;
    //            }
    //        }
    //    }
    //    //Upper wisker
    //    for(auto& elementHigherB : highOutliers){
    //        if(elementParent <= UpperBound && elementParent != elementHigherB){
    //            upperWiskerValue = elementParent;
    //        }
    //    }
    //}
    
}
/*
void Box_and_Wisker_Class::min(){
    bool LowerFound = false; 
    //for(auto& elementParent : sortedData){
        //Lower wisker
    #pragma omp parallel for schedule(static) firstprivate(sortedData)
    for(int i = 0; i<sortedData.size(); i++){
        if(sortedData[i]>=LowerBound & LowerFound == false){
            lowerWiskerValue = sortedData[i];
            LowerFound = true;
            cout<<"min "<<lowerWiskerValue<<endl;
            //return lowerWiskerValue;
        }
    }

}
void Box_and_Wisker_Class::max(){
    bool UpperFound = false;
    #pragma omp parallel for schedule(static) firstprivate(sortedData)
    for(int i = sortedData.size()-1; i>0; i--){
        if(sortedData[i]<=UpperBound & UpperFound == false){
            upperWiskerValue = sortedData[i];
            UpperFound = true;
            cout<<"max "<<upperWiskerValue<<endl;
            //return upperWiskerValue;
        }
    }
    
}
*/
/*
//For testing purposes
int main(){
    //vector<float> testData = {10,6,4,4,3,3,3,2,2,1};  //Outlier = 10
    vector<float> testData = {10,9,9,8,8,8,7,7,5,1};  //Outlier = 1
    Box_and_Wisker_Class Graph;

    Graph.sortData(testData);
    //Graph.computeValues();
    Graph.printData();

    return 0;
}
/**/