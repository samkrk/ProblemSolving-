#ifndef JUMPYNUM_HPP
#define JUMPYNUM_HPP

#include <iostream>
#include <cmath>
#include <fstream>

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

    int printFirstN(int low , int high){
        std::ofstream file("output.csv");  // Create and open the CSV file
        
        if (file.is_open()) {
            // Write the header
            file << "Nums\n";
            
            std::vector<int> nums;
            int count = 0;
            int k = low;
            while (k < high){
                if (isJumpy(k)){
                    count ++;
                    nums.push_back(k);
                }
                k++;
            }


            // other function 
            std::vector<int> second;
            // main while loop ensuring low < high 
            int num = low;
            count = 0;
            while (num <= high){
                // if num is not jumpy, calculate next jumpy number 
                if (!isJumpy(num)){
                    // find difference 
                    int temp = num;
                    int curr = temp % 10; // get last digit 
                    int power = 0;
                    temp /= 10; // divide temp by 10

                    while (temp > 0){
                        int prev = curr;
                        curr = temp % 10;
                        temp /= 10;
                        power++;
                        // std::cout << "prev: " << prev << " current: " << curr << " Number: " << temp << std::endl;
                        if (std::abs(curr-prev) < 2){
                            
                            int skip = ( (2 - std::abs(curr-prev) ) * pow(10,power-1));
                            // std::cout << num << " " << skip << std::endl;
                            num += skip;
                            if (skip > 10 && num % 10 != 0){
                                num -= num % 10;
                            };
                            continue;
                        }
                    }
                    continue;
                }
                else {
                    second.push_back(num);
                    count++;
                    num++;
                }
            }


            // Write the values from the vectors
            for (size_t i = 0; i < nums.size(); ++i) {
                file << nums[i] << "," << second[i] <<"\n";
            }

            file.close();  // Close the file
            std::cout << "Data has been written to output.csv\n";
        } else {
            std::cerr << "Unable to open the file.\n";
        }
        
        /*
        for (int i = 0 ; i < nums.size() ; i++){
            std::cout << nums.at(i) << " ";
        }
        std::cout << std::endl;
        */
        return 0;
    }

    int howMany(int low, int high){
        std::vector<int> nums;
        // main while loop ensuring low < high 
        int num = low;
        int count = 0;
        while (num <= high){
            // if num is not jumpy, calculate next jumpy number 
            if (!isJumpy(num)){
                // find difference 
                int temp = num;
                int curr = temp % 10; // get last digit 
                int power = 0;
                temp /= 10; // divide temp by 10

                while (temp > 0){
                    int prev = curr;
                    curr = temp % 10;
                    temp /= 10;
                    power++;
                    
                    // std::cout << "prev: " << prev << " current: " << curr << " Number: " << temp << std::endl;
                    if (std::abs(curr-prev) < 2){
                        
                        int skip = pow(10,power-1);
                        std::cout << "Num: " << num << " Skip: " << skip;
                        num += skip;
                        if (skip > 10 && num % 10 != 0){
                            num -= num % (skip)/10;
                            std::cout << " new num: " << num << std::endl;
                        }
                        else{
                            std::cout << std::endl;
                        }
                        continue;
                    }
                }
                continue;
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