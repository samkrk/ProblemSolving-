#include "Multiples/Multiples.hpp"
#include "RunLengthEncoding/RunLengthEncoding.hpp"

#include <iostream>

int main(void){
    RunLengthEncoding r;
    


    std::cout << r.decode("123456789012345678901234567890B") << std::endl;
}


