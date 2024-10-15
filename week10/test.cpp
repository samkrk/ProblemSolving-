
#include "DifferentStrings/DifferentStrings.hpp"
#include "BigBurger/BigBurger.hpp"
#include <iostream>

int main(void){

    BigBurger b;

    std::vector<int> arrival = {3,3,9};
    std::vector<int> service = {2,15,14};
    std::cout << b.maxWait(arrival,service) << std::endl; // 11

    arrival = {182};
    service = {11};
    std::cout << b.maxWait(arrival,service) << std::endl; // 0

    arrival = {2,10,11};
    service = {3,4,3};
    std::cout << b.maxWait(arrival,service) << std::endl; // 3

    arrival = {2,10,12};
    service = {15,1,15};
    std::cout << b.maxWait(arrival,service) << std::endl; // 7

}