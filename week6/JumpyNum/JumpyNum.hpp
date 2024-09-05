#ifndef JUMPYNUM_HPP
#define JUMPYNUM_HPP

#include <iostream>
#include <cmath>

class JumpyNum{
    public:

    bool isJumpy(int num){
        int temp = num;
        int curr = temp % 10; // get last digit 
        temp /= 10; // divide temp by 10

        while (temp > 0){
            int prev = curr;
            curr = temp % 10;
            temp /= 10;
            // std::cout << "prev: " << prev << " current: " << curr << " Number: " << temp << std::endl;
            if (std::abs(curr-prev) < 2){
                return false;
            }
        }
        return true;
    }

    int howMany(int low, int high){
        std::vector<int> nums;
        // main while loop ensuring low < high 
        int num = low;
        int count = 0;
        while (num <= high){
            // if num is not jumpy, calculate next jumpy number 
            if (!isJumpy(num)){
                int temp = num;
                int order = 0;
                int prev = temp % 10;
                temp /= 10;
                int curr = temp % 10;

                while (temp > 0){
                    if (std::abs(prev-curr) < 2){ // if we find the two adjacent numbers that aren't jumpy
                        int power = pow (10, order); 
                        if (power > 1){
                            // std::cout << "Num: " << num << " Power: " << power << std::endl;
                            num += power;
                            // std::cout << "(num % (power/10)): " << (num % (power)) << std::endl;
                            num = num - (num % (power));
                            break;
                        }
                        else { 
                            num++;
                            break;
                        }
                    }
                    else {
                        prev = curr;
                        temp /= 10;
                        curr = temp % 10;
                        order++;
                        continue;
                    }
                }
            }
            else {
                nums.push_back(num);
                count++;
                num++;
            }
        }
         /*
        for (int i = 0 ; i < nums.size() ; i++){
            std::cout << nums.at(i) << " ";
        }
        std::cout << std::endl;
         */
        return count;
    }
    

};


#endif