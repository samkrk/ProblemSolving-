#ifndef QUICKSUMS_HPP
#define QUICKSUMS_HPP

#include <iostream>

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
        /*
        std::cout << "Now trying with numbers ";
        for (int i = 0 ; i < numbers.size() ; i++){
            std::cout << numbers.at(i) << " ";
        }
        std::cout << "Looking for sum: " << sum << std::endl;
        */

        // base case where numbers = sum 
        int total = getTotal(numbers);
        if (total == sum){
            return 0;
        }

        // if total is less than sum we have to go back 
        if (total < sum){
            // std::cout << "Total less than sum, returning -1 " << std::endl;
            return -1;
        }

        // else we try minSums again from the furthest away possible digit
        // std::cout << "Start index: " << start_index << std::endl;
        int i = numbers.size()-1;
        while(i > 0){
            // std::cout << "Trying length: " << i << std::endl;
            int next_sum = getTotal(numbers.substr(0,i));
            // std::cout << "Next sum: " << next_sum << std::endl;
            if (next_sum == 0){
                i--;
                continue;
            }
            if (next_sum > sum){
                i--;
                continue;
            }
            else {
                // std::cout << "Recursive called" << std::endl;
                int res = minSums(numbers.substr(i, numbers.size()+1), sum-next_sum);
                if (res < 0){
                    i--; 
                    continue;
                }
                else{
                    return 1 + res;
                }
            }
        }
        // std::cout << "failed" << std::endl;
        return -1;
        
    }

};

#endif