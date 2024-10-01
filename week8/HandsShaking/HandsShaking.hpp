#ifndef HANDSSHAKING_HPP
#define HANDSSHAKING_HPP

#include <iostream>
#include <vector>

class HandsShaking{
    public:

    long rec(int n, std::vector<long>& memo){
        if (n < 0){
            std::cout << "Error here " << std::endl;
            return 0;
        }
        // if we have the answer to n already
        if (memo.at(n) != 0){
            return memo.at(n);
        }

        // otherwise we need to calculate it 
        long first = 0;
        long second = 0;
        long res = 0;
        for (int i = 2 ; i <= n ; i += 2){
            first = rec(i-2, memo);
            // std::cout << "First: " << first << "| i: " << i << std::endl;
            second = rec(n-i ,memo);
            // std::cout << "Second: " << first << "| i: " << i << std::endl;
            res += first * second;
        }
        
        // store in memo 
        memo.at(n) = res;
        return res;
    }

    long countPerfect(int n){
        // set up memoisation table 
        std::vector<long> memo (52, 0);
        memo.at(0) = 1;
        memo.at(2) = 1;
        memo.at(4) = 2;
        memo.at(6) = 5;
        //memo.at(7) = 14;

        // check for odd numbers 
        if (n % 2 != 0){
            return 0;
        }

        // call recursively 
        long res = rec(n,memo);
        return res;
    }

};


#endif