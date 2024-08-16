#include <iostream>
#include "ExerciseMachine/ExerciseMachine.hpp"
#include "SimpleCompressor/SimpleCompressor.hpp"

int main(void){

    ExerciseMachine m;
    std::string input = "10:39:58";
    std::cout << m.getPercentages(input) << std::endl;
}

