#include "Multiples/Multiples.hpp"
#include "RunLengthEncoding/RunLengthEncoding.hpp"
#include "RGBStreet/RGBStreet.hpp"

#include <iostream>

int main(void){
    
    RGBStreet street;
    
    std::vector<std::string> prices;
    
    prices.push_back("30 19 5");
    prices.push_back("64 77 64");
    prices.push_back("15 19 97");
    prices.push_back("4 71 57");
    prices.push_back("90 86 84");
    prices.push_back("93 32 91");
   

    std::cout << street.estimateCost(prices) << std::endl;
    
    return 0;
}


