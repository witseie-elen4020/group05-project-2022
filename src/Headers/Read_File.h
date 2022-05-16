#ifndef READ_FILE_H
#define READ_FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <omp.h>
#include <filesystem>

//class Magnitude;
class Read_File{
public:
    void read(std::string fname);
    void file_input();
    std::vector<float> get_x(){return x;};
    std::vector<float> get_y(){return y;};
    std::vector<float> get_z(){return z;};
    std::vector<float> get_mags(){return magnitudes;};
    bool get_s(){return s;};
    bool get_end(){return end;};
    int get_count(){return count;};
    int get_index(){return index;};
    void prints();
    void read_mag(float x, float y, float z);
    void magnitude();
    void read_multiple();
    void read_dir(string dir);
private:
    //float time;
    int count = 0;
    //std::vector<std::vector<std::string>> data;
    int index = 0;
	std::vector<std::string> files, dirs;//row, files;
    //std::vector<std::string> row;
    std::vector<float> x, x2, magnitudes;
    std::vector<float> y, y2;
    std::vector<float> z, z2;
	std::string line, word;
    //omp_lock_t writelock;
    bool s = false;
    bool end = false;
};
#endif