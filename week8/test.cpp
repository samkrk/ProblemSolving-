#include "FillBox/FillBox.hpp"

#include <iostream>

int main(void){
    FillBox b;
     std::vector<int> cubes = {10,10,10}; 
     std::cout << b.minCubes(5,5,9,cubes) << std::endl;
    
    return 0;
}


