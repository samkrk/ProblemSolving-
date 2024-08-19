#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include "PaternityTest/PaternityTest.hpp"
#include <iostream>

int main(void){

    PaternityTest p;

    std::string child = "WXETPYCHUWSQEMKKYNVP";
    

    std::string mother = "AXQTUQVAUOSQEEKCYNVP";
    
    
    std::vector<std::string> fathers;
    fathers.push_back("WNELPYCHXWXPCMNKDDXD");
    fathers.push_back("WFEEPYCHFWDNPMKKALIW");
    fathers.push_back("WSEFPYCHEWEFGMPKIQCK");
    fathers.push_back("WAEXPYCHAWEQXMSKYARN");
    fathers.push_back("WKEXPYCHYWLLFMGKKFBB");
    
    std::vector<int> res = p.possibleFathers(child,mother,fathers);

    for (int i = 0 ; i < res.size() ; i++){
        std::cout << res.at(i) << " ";
    }
    std::cout << std::endl;

}