#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <sstream>

int main()
{
    std::ifstream data_file{"input.txt"};
    
    int number{};
    int n1;
    int n2;
    int rows{0};
    std::vector<int>numbers{};

    std::string number_as_string;
    while (std::getline(data_file, number_as_string, ','))
    {
        numbers.push_back(std::stoi(number_as_string));
    }

        std::cout << "\nInitial state: ";
        for (int x : numbers)
        {
            std::cout << x << ", ";
        }

    for (int i = 1; i <= 80; i++)
    {
        int numbers_size = numbers.size();
        for (int j = 0; j < numbers_size; j++)
        {
            numbers[j]--;
            if (numbers[j] < 0)
            {
                numbers.push_back(8);
                numbers[j] = 6;
            }
            
        }
        std::cout << "\nAfter " << i << "days: ";
        for (int x : numbers)
        {
            std::cout << x << ", ";
        }
    }

    std::cout << "\nANSWER: " << numbers.size() << "\n";
    return 0;
}