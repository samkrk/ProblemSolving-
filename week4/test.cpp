#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include <iostream>

int main(void){

    TimeTravellingCellar t;
    std::vector<int> p;
    p.push_back(1000); 
    p.push_back(500); 
    p.push_back(250); 
    p.push_back(125); 
    
    std::vector<int> d;
    d.push_back(64);
    d.push_back(32);
    d.push_back(16);
    d.push_back(8);
     

    std::cout << t.determineProfit(p,d) << std::endl;
}