//Author: Keowa Pretorius - 1877616
#include "Box_and_Wiskper.h"

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
    cout << "Sorted vector is:" << endl;
    for(auto & element : sortedData){
        cout << element << "  ";
    }
    cout << endl;
    cout << "VecSize = " << DataSize  << endl;
    cout << "Lower wisker = " << lowerWiskerValue << " Q1 = " << Q1Value << " Q2 = " << medianValue << " Q3 = " << Q3Value << " Upper wisker = " << upperWiskerValue << endl;

    cout << "Lower outliers:" << endl;
    for(auto & element : lowOutliers){
        cout << element << "  ";
    }
    cout << endl;
    cout << "Higher outliers:" << endl;
    for(auto & element : highOutliers){
        cout << element << "  ";
    }
    cout << endl;
}

void Box_and_Wisker_Class::computeQ1() {
    if(DataSize/2 % 2 == 0){   //Vector size is even
        Q1Value = (sortedData.at(DataSize/4 - 1) + sortedData.at(DataSize/4))/2;
    }else { //Vector size is odd
        Q1Value = sortedData.at(DataSize/4);
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
    }else { //Vector size is odd
        Q3Value = sortedData.at(3*DataSize/4);
    }
}

void Box_and_Wisker_Class::computeBoundariesandOutliers() {
    IQRValue = Q3Value - Q1Value;
    LowerBound = Q1Value - 1.5*IQRValue;
    UpperBound = Q3Value + 1.5*IQRValue;

    for(auto & element : sortedData){
        if(element < LowerBound){
            lowOutliers.push_back(element);
        }
        if(element > UpperBound){
            highOutliers.push_back(element);
        }
    }
    sort(lowOutliers.begin(), lowOutliers.end());
    sort(highOutliers.begin(), highOutliers.end());

    computeWiskerBoundaries();
}

void Box_and_Wisker_Class::computeWiskerBoundaries() {
    bool LowerFound = false; 
    for(auto & elementParent : sortedData){
        //Lower wisker
        if(!LowerFound){
            for(auto & elementLowerB : lowOutliers){
                if(elementParent >= LowerBound && elementParent != elementLowerB){
                    lowerWiskerValue = elementParent;
                    LowerFound = true;
                }
            }
        }
        //Upper wisker
        for(auto & elementHigherB : highOutliers){
            if(elementParent <= UpperBound && elementParent != elementHigherB){
                upperWiskerValue = elementParent;
            }
        }
    }
}

//For testing purposes
/*
int mainKeowa(){
    //vector<float> testData = {10,6,4,4,3,3,3,2,2,1};  //Outlier = 10
    vector<float> testData = {10,9,9,8,8,8,7,7,5,1};  //Outlier = 1
    Box_and_Wisker_Class Graph;

    Graph.sortData(testData);
    //Graph.computeValues();
    Graph.printData();

    return 0;
}
*/