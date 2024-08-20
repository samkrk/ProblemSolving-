#include "TimeTravellingCellar/TimeTravellingCellar.hpp"
#include "PaternityTest/PaternityTest.hpp"
#include "UnsealTheSafe/UnsealTheSafe.cpp"
#include <iostream>

int main(void){

    UnsealTheSafe s;
    std::cout << s.countPasswords(25) << std::endl;

}

