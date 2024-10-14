
#include <iostream>
#include "CatGame/CatGame.hpp"
#include "CellRemoval/CellRemoval.hpp"
#include "CubeStickers/CubeStickers.hpp"
#include "ErdosNumber/ErdosNumber.hpp"

int main(void){

    ErdosNumber e;
    std::vector<std::string> authorList = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
 "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
    std::vector<std::string> res = e.calculateNumbers(authorList);
    for (std::string val : res){
        std::cout << val << std::endl;
    }
    std::cout << std::endl;

    authorList = {"ERDOS B", "A B C", "B A E", "D F"};
    res = e.calculateNumbers(authorList);
    for (std::string val : res){
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
    
    authorList = {"ERDOS ARRARRARRARRARRARRARRARRARRARRARRARRARRARRAR", "ARRARRARRARRARRARRARRARRARRARRARRARRARRARRAR JOHN", "ERRERRERRERRERRERRERRERRERRERRERRERRERRERRERRERROR"};
    res = e.calculateNumbers(authorList);
    for (std::string val : res){
        std::cout << val << std::endl;
    }
    std::cout << std::endl;


}