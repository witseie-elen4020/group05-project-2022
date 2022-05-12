#include "../Headers/Read_File.h"

void Read_File::read(std::string fname){
        
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
                //if(count <= 0)
                 //   data.push_back(row);
                if(count>0){
               // float n = std::stof(rwo);
                x.push_back(std::stof(row[2]));
                y.push_back(std::stof(row[3]));
                z.push_back(std::stof(row[4]));
                //data.push_back(row);
                }
                count++;
                
            }
           // return data;
        }
        else{
            std::cout<<"Could not open the file\n";
            //return -1;
        }
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
