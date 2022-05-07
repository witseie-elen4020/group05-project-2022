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
	std::vector<std::vector<std::string>> data = file.read("Accelerometer.csv", 0.2, 0.3);
	file.seperate(data);
	x = file.get_x();
	y = file.get_y();
	z = file.get_z();
	file.prints();
    file.print(data);
 
	
	return 0;
}