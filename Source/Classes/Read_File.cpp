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
void Read_File::print1(std::vector<float> val){
    for(int i=0;i<val.size();i++){
            std::cout<<val[i]<<" ";
            }
            std::cout<<"\n";
}
void Read_File::prints(){
    print1(x);
    print1(y);
    print1(z);
}
void Read_File::seperate(std::vector<std::vector<std::string>> data){
    //std::cout<<data.size()<<std::endl;
    //std::cout<<data[2].size()<<std::endl;
    for(int i=2;i<data[i].size();i++){
                for(int j=1;j<data.size();j++){
			        if(i==2){
                        float n = std::stof(data[j][i]);
                        x.push_back(n);
                    }
                    if(i==3){
                        float n = std::stof(data[j][i]);
                        y.push_back(n);
                    }
                    if(i==4){
                        float n = std::stof(data[j][i]);
                        z.push_back(n);
                    }
                    else{
                        continue;
                    }
                }
		        std::cout<<"\n";
            }
}
/*
void Read_File::del_col(std::vector<std::vector<std::string>> & data, int col){
    int i = col;
    std::vector<int>::iterator iter = data[i].begin();
    std::vector<int>::iterator it = data[i].end();
    while( iter != it){
			data.erase(iter);
            
        }

}
*/