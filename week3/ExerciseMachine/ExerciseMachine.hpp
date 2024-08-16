#ifndef EXERCISEMACHINE_HPP
#define EXERCISEMACHINE_HPP

#include <iostream>

class ExerciseMachine{
public: 
    int getPercentages(std::string time){
        double seconds = 0;
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

        
        double one_percent = seconds/100;
        double total_percent = one_percent;
        const double TOLERANCE = 1e-9;
        
        int num_percents = 1;
        while (std::abs(std::floor(total_percent) - total_percent) > TOLERANCE && num_percents < 100){
            total_percent += one_percent;
            num_percents++;
        }
    
        // calculate number of functions calls 
        return 100/num_percents -1;
    }
};

#endif