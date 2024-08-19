#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include <iostream>

int main(void){

    TimeTravellingCellar t;
    std::vector<int> p;
    p.push_back(9400); 
    p.push_back(9270); 


    
    std::vector<int> d;
    d.push_back(526);
    d.push_back(1252);
    
     

    std::cout << t.determineProfit(p,d) << std::endl;
}