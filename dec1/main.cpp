#include <vector>
#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::ifstream data_file{"input.txt"};
    int deeper = 0;
    int prev_depth{};
    data_file >> prev_depth;
    int depth{};
    while(data_file >> depth){
        if(prev_depth < depth) {
            deeper++;
            std::cout << depth - prev_depth << std::endl;
        }
        prev_depth = depth;
    }
    
    
    std::cout << deeper << std::endl;
}