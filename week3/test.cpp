#include <iostream>
#include "QuickSums/QuickSums.hpp"

int main(void){

    QuickSums s;
    std::string nums = "000009230560001";
    std::cout << s.minSums(nums,71) << std::endl;
}

