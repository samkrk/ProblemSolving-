#ifndef MULTIPLES_HPP
#define MULTIPLES_HPP

#include <iostream>

class Multiples{
    public:

    int number(int min, int max, int factor){
        int count = 0;
        for (int i = min ; i <= max ; i++){
            if (i % factor == 0){
                count++;
            }
        }
        return count;
    }
};



#endif