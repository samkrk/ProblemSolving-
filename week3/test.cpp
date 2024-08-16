#include <iostream>
#include "ExerciseMachine/ExerciseMachine.hpp"
#include "SimpleCompressor/SimpleCompressor.hpp"

int main(void){

    SimpleCompressor c;
    std::string t = "C[2[2A]B]D";
    std::string res = c.uncompress(t);
    for (int i = 0 ; i < res.size() ; i++){
        std::cout << res.at(i);
    }
    std::cout<<std::endl;
}

