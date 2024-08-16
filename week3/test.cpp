#include <iostream>
#include "ExerciseMachine/ExerciseMachine.hpp"
#include "SimpleCompressor/SimpleCompressor.hpp"
#include "QuickSums/QuickSums.hpp"

int main(void){

    QuickSums s;
    std::string nums = "0123456789";
    std::cout << s.minSums(nums,45) << std::endl;
}

