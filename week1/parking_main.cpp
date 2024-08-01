#include "StreetParking/StreetParking.hpp"

#include <iostream>

int main(void){
    StreetParking parker;

    std::cout << parker.freeParks("SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D")<< std::endl;
}