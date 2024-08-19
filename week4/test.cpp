#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include "PaternityTest/PaternityTest.hpp"
#include <iostream>

int main(void){

    PaternityTest p;

    std::string child = "ABABAB";
    

    std::string mother = "ABABAB";
    
    
    std::vector<std::string> fathers;
    fathers.push_back("ABABAB");
    fathers.push_back("ABABCC");
    fathers.push_back("ABCCDD");
    fathers.push_back("CCDDEE");
    
    std::vector<int> res = p.possibleFathers(child,mother,fathers);

    for (int i = 0 ; i < res.size() ; i++){
        std::cout << res.at(i) << " ";
    }
    std::cout << std::endl;

}