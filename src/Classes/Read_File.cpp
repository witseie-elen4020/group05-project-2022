#include "../Headers/Read_File.h"
//#include <filesystem>
void Read_File::file_input(){
    string userInput, type;
    cout << "To enter a file/multiple file paths enter 'F'" << endl;
    cout << "To enter a file directory enter 'D'" << endl;
    cout << "When done entering multiple files or a directory, enter 'E' to exit" << endl;
    cin>>userInput;
    if(userInput=="F"){
    while (userInput != "E")    // Loop until user enters the letter e
        {
            cout << "Please enter file path name" << endl;
            cin >> userInput;
            if(userInput != "E"){
            files.push_back(userInput); //store file names into files vector
            }
        }
        cout<<files.size()<<endl;
    }
    if(userInput=="D"){
    while (userInput != "E")    // Loop until user enters the letter e
        {
            cout << "Please enter adirectory name" << endl;
            cin >> userInput;
            if(userInput != "E"){
            read_dir(userInput); //store file names from directory into files vector
            }
        }
        cout<<files.size()<<endl;
    }

}
void Read_File::read(std::string fname){
        int cont=0;
        std::vector<std::string> row;
        std::fstream file (fname, std::ios::in);
        if(file.is_open())
        {
            getline(file, line);
            while(getline(file, line))
            {
                
                row.clear();
    
                std::stringstream str(line);

                while(getline(str, word, ',')){
                    row.push_back(word);
                    
                }
                
                x.push_back(std::stof(row[2]));
                y.push_back(std::stof(row[3]));
                z.push_back(std::stof(row[4]));
                
                /*
                if(cont==100){
                    s = true;
                    cout<<"s true"<<endl;
                }
                //read_mag is for when the file reads and calculates the magnitude
                //read_mag(std::stof(row[2]),std::stof(row[3]),std::stof(row[4]));
                //}
               // cont++;
               */
                
            }
           // return data;
           end  = true;
        }
        else{
            std::cout<<"Could not open the file\n";
            //return -1;
        }
    }
void Read_File::read_multiple(){
    int i;
    //files.size()
    for(  i = 0 ; i<1 ; i++ ){
        read(files[i]);
    }
    
}
void Read_File::read_dir(string dir){
    string path = "/";

    for (const auto & file : std::filesystem::directory_iterator(dir)){
        files.push_back(file.path());
        cout << file.path() << endl;
    }

}
void Read_File:: read_mag(float x, float y, float z){
    float sum = pow(x,2) + pow(y,2) + pow(z,2);
    sum = sqrt(sum);
    magnitudes.push_back(sum);
    
}
