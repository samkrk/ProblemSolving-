#include "ElevatorLimit/ElevatorLimit.hpp"

#include <iostream>
#include <vector>

int main(void){
    ElevatorLimit el;
    std::vector<int> entered;
    std::vector<int> exit;
    
    entered.push_back(6);
    entered.push_back(85);
    entered.push_back(106);
    entered.push_back(1);
    entered.push_back(199);
    entered.push_back(76);
    entered.push_back(162);
    entered.push_back(141);

    
    exit.push_back(38);
    exit.push_back(68);
    exit.push_back(62);
    exit.push_back(83);
    exit.push_back(170);
    exit.push_back(12);
    exit.push_back(61);
    exit.push_back(114);

    std::vector<int> res = el.getRange(entered,exit,668);

    for (int i = 0 ; i < res.size() ; i ++){
        std::cout << res.at(i) << std::endl;
    }

    return 0;
}