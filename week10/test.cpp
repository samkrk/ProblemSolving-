
#include "DifferentStrings/DifferentStrings.hpp"
#include "BigBurger/BigBurger.hpp"
#include "BridgeSort/BridgeSort.hpp"
#include <iostream>

int main(void){

    BridgeSort b;

    std::string hand = "HAH2H3C4D5ST";
    std::cout << b.sortedHand(hand) << std::endl; // C4D5H2H3HAST

    hand = "H3SAHA";
    std::cout << b.sortedHand(hand) << std::endl; // H3HASA

}