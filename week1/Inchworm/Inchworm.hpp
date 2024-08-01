#ifndef INCHWORM_HPP
#define INCHWORM_HPP

#include <iostream>
#include <cmath>
#include <numeric> // for std::gcd

class Inchworm
{
public:
    int lcm(int a, int b){
            return (a / std::gcd(a, b)) * b;
    }
    int lunchtime(int branch, int rest, int leaf)
    {
        int res = 0;

        // don't divide by zero
        if (rest == 0 || leaf == 0) {
            return 0;
        }

        // Increment by the least common multiple of leaf and rest to find common positions
        for (int i = 0; i <= branch; i += lcm(leaf, rest)) {
            res++;
        }

        return res;  
    }
};

#endif
