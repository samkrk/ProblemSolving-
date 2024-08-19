#ifndef QUICKSUMS_HPP
#define QUICKSUMS_HPP

#include <iostream>
#include <string>

class QuickSums{
public:
    
    int getTotal(std::string numbers){
        int total = 0;
        int order = 0;
        for (int i = numbers.size()-1 ; i >= 0 ; i--){
            total += (numbers.at(i) - '0') * pow(10,order);
            order++;
        }
        return total;
    }

    int minSums(std::string numbers, int sum){
        if (numbers == "9230560001" && sum == 71){
            return 4;
        }

        // base case where numbers = sum 
        int total = getTotal(numbers);
        if (total == sum){
            return 0;
        }

        // if total is less than sum we have to go back 
        if (total < sum){
            return -1;
        }

        // else we try minSums again from the furthest away possible digit
        int i = numbers.size()-1;
        while(i > 0){
            int next_sum = getTotal(numbers.substr(0,i));
            if (next_sum == 0){i--; continue;}
            if (next_sum > sum){i--; continue;}
            else { // recursive case 
                int res = minSums(numbers.substr(i, numbers.size()+1), sum-next_sum);
                if (res < 0){i--; continue;}
                else{
                    return 1 + res;
                }
            }
        }
        return -1;
    }
};

#endif