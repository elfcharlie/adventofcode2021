#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream data_file{"input2.txt"};

    int x{};
    int y{};
    int aim{};
    std::string direction{""};
    int amount{};
    while(data_file >> direction){
        data_file >> amount;
        if(direction == "forward"){
            x += amount;
            y += amount * aim;
        }
        else if (direction == "up"){
            aim -= amount;
        }
        else if (direction == "down"){
            aim += amount;
        }
    }
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << x * y << std::endl;
}