#ifndef GOODHOURS_HPP
#define GOODHOURS_HPP

#include <iostream>

class GoodHours{
    public:

    std::string incrementTime(std::string currTime) {
    int hours = std::stoi(currTime.substr(0, 2));
    int minutes = std::stoi(currTime.substr(3, 2));

    // Increment minutes
    minutes++;
    if (minutes == 60) {
        minutes = 0;
        hours++;
    }
    if (hours == 24) {
        hours = 0;
    }

    // Format back to HH:MM
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", hours, minutes);
    return std::string(buffer);
}

    int howMany(std::string beforeTime, std::string afterTime){

        int count = 0;
        std::string currTime = beforeTime;
        while (currTime != afterTime){
            int h0 = currTime.at(0) - '0';
            int h1 = currTime.at(1) - '0';
            int m0 = currTime.at(3) - '0';
            int m1 = currTime.at(4) - '0';

            if ((h0 == h1 * m0 * m1) || (h0 * h1 == m0 * m1) || (h0 * h1 * m0 == m1)) {
            count++;
             }

            currTime = incrementTime(currTime);
        }

        // need to check last one
        int h0 = currTime.at(0) - '0';
        int h1 = currTime.at(1) - '0';
        int m0 = currTime.at(3) - '0';
        int m1 = currTime.at(4) - '0';
        if ((h0 == h1 * m0 * m1) || (h0 * h1 == m0 * m1) || (h0 * h1 * m0 == m1)) {
            count++;
        }

            

        return count;
        
    }


};

#endif