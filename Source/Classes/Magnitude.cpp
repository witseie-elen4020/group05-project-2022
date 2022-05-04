#include "../Headers/Magnitude.h"

Magnitude::Magnitude(){

}

Magnitude::Magnitude(vector<float> &x,vector<float> &y, vector<float> &z){
    calcProcess(x,y,z);
}

void Magnitude::calcProcess(vector<float> &x,vector<float> &y, vector<float> &z){
    
    if(x.size() == y.size() && x.size() == z.size() ){
        for (int i = 0; i < x.size(); i++)
        {
            calcMagnitude(x[i],y[i],z[i]);
        }
    }

    else{cout<<"incorrect sizes\n";};
}

void Magnitude::calcMagnitude(float x,float y, float z){
    float sum = pow(x,2) + pow(y,2) + pow(z,2);
    sum = sqrt(sum);
    magnitudes.push_back(sum);
}

vector<float>& Magnitude::getMagnitudes(){
    return magnitudes;
}