#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "./Classes/Read_File.cpp"
 
using namespace std;

int main()
{
	vector<float> x,y,z;
    Read_File file;
	file.read("Accelerometer.csv");
	x = file.get_x();
	y = file.get_y();
	z = file.get_z();
 
	
	return 0;
}