#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include "PaternityTest/PaternityTest.hpp"
#include "UnsealTheSafe/UnsealTheSafe.hpp"
#include "MonstersValley2/MonstersValley2.hpp"
#include <iostream>

int main(void){

    MonstersValley2 m;
    std::vector<int> monsters;
    monsters.push_back(1);
    monsters.push_back(2);
    monsters.push_back(4);
    monsters.push_back(10000);
   

    std::vector<int> cost;
    cost.push_back(1); 
    cost.push_back(1); 
    cost.push_back(1); 
    cost.push_back(2); 
     
    std::cout << m.minimumPrice(monsters,cost) << std::endl;

}

