#include "DerivativeSequence/DerivativeSequence.hpp"

#include <iostream>
#include <vector>

int main(void){
    DerivativeSequence seq;
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(9);
    numbers.push_back(-1);
    
    
    std::vector<int> result = seq.derSeq(numbers, 4);

    std::cout << "Derivative sequence: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}