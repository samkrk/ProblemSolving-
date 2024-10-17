
#include "DifferentStrings/DifferentStrings.hpp"
#include "BigBurger/BigBurger.hpp"
#include "BridgeSort/BridgeSort.hpp"
#include "BlockEnemy/BlockEnemy.hpp"
#include <iostream>

int main(void){

    BlockEnemy b;
    

    
    int N1 = 12;
    std::vector<std::string> cities1 = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
    "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
    std::vector<int> occupied1 = {1, 2, 6, 8};

    std::cout<< b.minEffort(N1,cities1,occupied1) << std::endl; // 13
    
    
    int N = 5;
    std::vector<std::string> cities = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
    std::vector<int> occupied = {3, 2, 4};
    std::cout<< b.minEffort(N,cities,occupied) << std::endl; // 4
    
    
    N = 5;
    cities = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
    occupied = {3};
    std::cout<< b.minEffort(N,cities,occupied) << std::endl; // 0


    N = 12;
    cities = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
    occupied = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::cout<< b.minEffort(N,cities,occupied) << std::endl; // 66

    
    
}