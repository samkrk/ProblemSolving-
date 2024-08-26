#include "Multiples/Multiples.hpp"
#include "RunLengthEncoding/RunLengthEncoding.hpp"
#include "RGBStreet/RGBStreet.hpp"
#include "HouseBuilding/HouseBuilding.hpp"
#include <iostream>

int main(void){
    
    HouseBuilding h;
    
    std::vector<std::string> levels;

       
    levels.push_back("5781252");
    levels.push_back("2471255");
    levels.push_back("0000291");
    levels.push_back("1212489");

    
    
    
    std::cout << h.getMinimum(levels) << std::endl;

    return 0;
}


