#include "Read_File.h"

std::vector<std::vector<std::string>> Read_File::read(std::string fname, float init_time, float final_time){
        
        std::fstream file (fname, std::ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                
                row.clear();
    
                std::stringstream str(line);

                while(getline(str, word, ',')){
                    row.push_back(word);
                }
                if(count <= 0)
                data.push_back(row);

                if(count>0){
                    if(std::stof(row[1])<init_time){
                    continue;
                    }
                    if(std::stof(row[1])>init_time && std::stof(row[1])<final_time){
                        data.push_back(row);
                    }
                    if(std::stof(row[1])>final_time){
                    break;
                    }
                }
                
                count++;
                
            }
        }
        else
            std::cout<<"Could not open the file\n";
            
        return data;
        }

void Read_File::print(std::vector<std::vector<std::string>> data){
            for(int i=0;i<data.size();i++){
                for(int j=0;j<data[i].size();j++){
			        std::cout<<data[i][j]<<" ";
                    }
		        std::cout<<"\n";
            }

        }