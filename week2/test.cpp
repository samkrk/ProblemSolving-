#include "MooingCows/MooingCows.hpp"
#include <iostream>
#include <vector>

int main(void){
    MooingCows thing;
    std::vector<std::string> farm;
    farm.push_back("CCCC");
    farm.push_back("CCCC");
    farm.push_back("CCCC");
    
    


    std::cout << thing.dissatisfaction(farm) << std::endl;
    
 
 
    return 0;
}