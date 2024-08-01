#include "BlackAndRed/BlackAndRed.hpp"

#include <iostream>

int main(void){
    BlackAndRed b;
    std::cout << b.cut("BBBRRRRB") << std::endl;

    return 0;
}