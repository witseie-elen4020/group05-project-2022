#ifndef READ_FILE_H
#define READ_FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


class Read_File{
public:
    std::vector<std::vector<std::string>> read(std::string fname, float init_time, float final_time);
    void print(std::vector<std::vector<std::string>> content);
private:
    //float time;
    int count = 0;
    std::vector<std::vector<std::string>> data;
	std::vector<std::string> row;
	std::string line, word;
};
#endif