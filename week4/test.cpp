#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include <iostream>

int main(void){

    TimeTravellingCellar t;
    std::vector<int> p;
    p.push_back(3); 
    p.push_back(2); 


    
    std::vector<int> d;
    d.push_back(1);
    d.push_back(2);
    
     

    std::cout << t.determineProfit(p,d) << std::endl;
}