#ifndef EXERCISEMACHINE_HPP
#define EXERCISEMACHINE_HPP

#include <iostream>

class ExerciseMachine{
public: 

    // Function to compute GCD of two numbers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to find the denominator of the fraction
    int getDenominator(int num) {
        int denominator = 100; // Since the input number represents a decimal with a denominator of 100
        int commonDivisor = gcd(num, denominator);
        return denominator / commonDivisor;
    }

    int getPercentages(std::string time){
        int seconds = 0;
        // calculate total time in seconds. 
        // seconds
        seconds += (time[7]-48);
        seconds += (time[6]-48) * 10;
        // minutes 
        seconds += (time[4]-48) * 60;
        seconds += (time[3]-48) * 600;
        //hours
        seconds += (time[1]-48) * 3600;
        seconds += (time[0]-48) * 36000;

        int num = seconds%100;
        return (100/getDenominator(num)) - 1;
        
    }
};

#endif