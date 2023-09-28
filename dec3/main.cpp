#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <math.h>

int bin_to_dec(std::array<int, 12> input);
int main(){
    std::ifstream data_file{"input.txt"};
    std::string number{""};
    int rows{0};
    std::array<int,12> gamma_rate = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::array<int,12> epsilon_rate = gamma_rate;
    int amount{};
    char c{};
    while (data_file >> number){
        rows++;
        for(int i = 0; i < number.size(); i++){
            c = number[i];
                if (c == '1'){
                    gamma_rate[i]++;
                }
                else if(c == '0'){
                    gamma_rate[i]--;
                }
            }
    }
    for(int i = 0; i < (sizeof(gamma_rate)/sizeof(gamma_rate[0])); i++){
        if (gamma_rate[i] >= 0){
            gamma_rate[i] = 1;
            epsilon_rate[i] = 0;
        }
        else {
            gamma_rate[i] = 0;
            epsilon_rate[i] = 1;
        }
    }
    for (int i : gamma_rate){
        std::cout << i;
    }
    std::cout << std::endl;
    for (int i : epsilon_rate){
        std::cout << i;
    }
    std::cout << std::endl;
    int gamma_rate_dec = bin_to_dec(gamma_rate);
    std::cout << gamma_rate_dec <<  std::endl;
    int epsilon_rate_dec =  bin_to_dec(epsilon_rate);
    std::cout << "ANSWER: " << gamma_rate_dec * epsilon_rate_dec << std::endl;
}

int bin_to_dec(std::array<int, 12> input){
    int decimal{0};
    int array_size = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < array_size; i++) {
        decimal += input[i] * pow(2,(array_size - i - 1));
    }
    return decimal;
}