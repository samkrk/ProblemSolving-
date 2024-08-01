#include "EggCartons/EggCartons.hpp"

#include <iostream>

int main(void){
    EggCartons carton; 
    std::cout << carton.minCartons(22) << std::endl;

    return 0;
}