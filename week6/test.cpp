#include "JumpyNum/JumpyNum.hpp"

#include <iostream>

int main(void){
    
    JumpyNum j;

    int n = 300;
    std::cout << j.howMany(0,2000000000) << std::endl;
    
    
    // 
    return 0;
}