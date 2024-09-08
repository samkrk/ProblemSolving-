#ifndef MINIMALDIFFERENCE_HPP
#define MINIMALDIFFERENCE_HPP

#include <iostream>

class MinimalDifference{
public:
    int getDigitSum(int X){
        int temp = X;
        int sum = 0;
        while (temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        return sum;
    }

    int findNumber(int A, int B, int C){
        if (C > A && C < B){
            return C;
        }

        if (A == B){
            return A;
        }

        // brute force time 
        int c = getDigitSum(C); // goal digit sum 
        int t = getDigitSum(A); // current digit sum 
        int minDigit = t; // current min digit sum
        int minInt = A; // corresponding int for the min digit sum 
        for (int i = A ; i <= B ; i++){ // loop through all values between A and B
            t = getDigitSum(i); // digit sum of X 
            int difference = std::abs(c - t); // new difference 
            
            if (difference == 0){ // if we found the answer 
                return i;
            }
            else if (difference < std::abs(c-minDigit)){ // 
                minDigit = t;
                minInt = i;
            }
        }
        return minInt;
    }

    
    

};
#endif