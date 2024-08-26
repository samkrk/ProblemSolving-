#include "Multiples/Multiples.hpp"
#include "RunLengthEncoding/RunLengthEncoding.hpp"
#include "RGBStreet/RGBStreet.hpp"
#include "HouseBuilding/HouseBuilding.hpp"
#include <iostream>

int main(void){
    
    HouseBuilding h;
    
    std::vector<std::string> levels;


    levels.push_back("000009");
    levels.push_back("100000");
    
    
    std::cout << h.getMinimum(levels) << std::endl;

    return 0;
}


