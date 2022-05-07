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
    void print(std::vector<std::vector<std::string>> data);
    //void del_col(std::vector<std::vector<std::string>> &data, int col);
    void seperate(std::vector<std::vector<std::string>> data);
    void print1(std::vector<float> val);
    std::vector<float> get_x(){return x;};
    std::vector<float> get_y(){return y;};
    std::vector<float> get_z(){return z;};
    void prints();
private:
    //float time;
    int count = 0;
    std::vector<std::vector<std::string>> data;
	std::vector<std::string> row;
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> z;
	std::string line, word;
};
#endif