# group05-project-2022

Build and Run Instructions:

1. Navigate to src Folder in Directory in the Group05 Home directory: /Project/group05-project-2022/src
2. Open Terminal in directory
3. run the following command in terminal
    * g++ -std=c++17 -fopenmp -lgomp main.cpp -o test 
4. execute the following by typing the following command
    * ./test
5. The Program will prompt the user for input. Input F for File, D for directory, E for end input
    *  If input was F: input the absolute Paths into the terminal and enter one by one. When done inputting file paths, Enter E
    *  If input was D: input the absolute Path of the folder into the terminal and enter one by one. When done inputting file paths, Enter E This will read the Each directory
    *  If input was E: No more inputs will be accepted and the program will begin reading files and computing values
