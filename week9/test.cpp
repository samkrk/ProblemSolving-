
#include "CatGame/CatGame.hpp"
#include <iostream>

int main(void){

    CatGame g;

    std::vector<int> coords = {3, 7, 4, 6, -10, 7, 10, 9, -5};
    int X = 7;
    std::cout << g.getNumber(coords, X) << std::endl;
    std::cout << std::endl;

    coords = {-4, 0, 4, 0};
    X = 4;
    std::cout << g.getNumber(coords, X) << std::endl;
    std::cout << std::endl;

    coords = {4, 7, -7};
    X = 5;
    std::cout << g.getNumber(coords, X) << std::endl;
    std::cout << std::endl;

    coords = {-3, 0, 1};
    X = 3;
    std::cout << g.getNumber(coords, X) << std::endl;
    std::cout << std::endl;

    coords = {-100000000, 100000000};
    X = 100000000;
    std::cout << g.getNumber(coords, X) << std::endl;
    std::cout << std::endl;

}