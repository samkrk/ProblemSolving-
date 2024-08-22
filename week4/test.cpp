#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include "PaternityTest/PaternityTest.hpp"
#include "UnsealTheSafe/UnsealTheSafe.hpp"
#include "MonstersValley2/MonstersValley2.hpp"
#include <iostream>

int main(void){

    MonstersValley2 m;
    std::vector<int> monsters;
    monsters.push_back(606);
    
    
    /*
    monsters.push_back(1999999994);
    monsters.push_back(1999999995);
    monsters.push_back(1999999996);
    monsters.push_back(1999999997);
    monsters.push_back(1999999998);
    monsters.push_back(1999999999);
    monsters.push_back(2000000000);
   */
   

    std::vector<int> cost;
    cost.push_back(2); 
    
    
    /*
    cost.push_back(1); 
    cost.push_back(1); 
    cost.push_back(1); 
    cost.push_back(1); 
    cost.push_back(1); 
    cost.push_back(1); 
    cost.push_back(1); 
    */
     
    std::cout << m.minimumPrice(monsters,cost) << std::endl;

}

