#include <iostream>
#include "ExerciseMachine/ExerciseMachine.hpp"
#include "SimpleCompressor/SimpleCompressor.hpp"

int main(void){

    ExerciseMachine m;
    std::string input = "19:21:52";
    std::cout << m.getPercentages(input) << std::endl;
}

