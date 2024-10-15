
#include "DifferentStrings/DifferentStrings.hpp"
#include <iostream>

int main(void){

    DifferentStrings d;

    std::string A = "koder";
    std::string B = "topcoder";
    std::cout << d.minimize(A,B) << std::endl; // 1 

    A = "hello";
    B = "xello";
    std::cout << d.minimize(A,B) << std::endl; // 1

    A = "abc";
    B = "topabcoder";
    std::cout << d.minimize(A,B) << std::endl; // 0

    A = "adaabc";
    B = "aababbc";
    std::cout << d.minimize(A,B) << std::endl; // 2

    A = "giorgi";
    B = "igroig";
    std::cout << d.minimize(A,B) << std::endl; // 6

}