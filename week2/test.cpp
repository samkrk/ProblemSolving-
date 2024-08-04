#include "ElevatorLimit/ElevatorLimit.hpp"

#include <iostream>
#include <vector>

int main(void){
    ElevatorLimit el;
    std::vector<int> entered;
    std::vector<int> exit;
    
    entered.push_back(0);
    entered.push_back(2);
    

    
    exit.push_back(1);
    exit.push_back(0);
   

    std::vector<int> res = el.getRange(entered,exit,1);

    for (int i = 0 ; i < res.size() ; i ++){
        std::cout << res.at(i) << std::endl;
    }

    return 0;
}