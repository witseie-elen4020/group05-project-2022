#ifndef MAGNITUDE_H
#define MAGNITUDE_H

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Magnitude{

    private:
        vector<float> magnitudes;

    public:
        Magnitude();
        Magnitude(vector<float> &x,vector<float> &y, vector<float> &z);

        void calcProcess(vector<float> &x,vector<float> &y, vector<float> &z);
        void calcMagnitude(float x,float y, float z);
        vector<float>& getMagnitudes();

};
#endif