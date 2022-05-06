#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "./Classes/Read_File.cpp"
 
using namespace std;

int main()
{
    Read_File file;
	std::vector<std::vector<std::string>> data = file.read("Accelerometer.csv", 0.2, 0.3);
    file.print(data);
 
	
	return 0;
}