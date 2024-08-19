#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include <iostream>

int main(void){

    TimeTravellingCellar t;
    std::vector<int> p;
    p.push_back(7116); 
    p.push_back(8936); 


    
    std::vector<int> d;
    d.push_back(9309);
    d.push_back(536);
    
     

    std::cout << t.determineProfit(p,d) << std::endl;
}