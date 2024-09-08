#include "TaliluluCoffee/TaliluluCoffee.hpp"

#include <iostream>


int main(void){


    TaliluluCoffee t;

    std::vector<int> tips = {7, 8, 6, 9, 10,1};

    std::cout << t.maxTip(tips) << std::endl;

    
}
