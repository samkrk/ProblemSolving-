#ifndef COLORFULRABBITS_HPP
#define COLORFULRABBITS_HPP

#include <iostream>
#include <map>

class ColorfulRabbits{
    public:

    int getMinimum(std::vector<int> replies){
        // initialise min variable 
        int min = 0;

        // Create a map to store rabbit counts 
        std::map<int, int> rabbitCount;

        // get rabbit counts 
        for (int i = 0 ; i < replies.size() ; i++){
            rabbitCount[replies.at(i)]++; // increment frequency
        }

        // go through each occurance 
        for (auto& x : rabbitCount){
            if (x.second > x.first){ 
                int temp = x.first + 1;
                while (temp < x.second){
                    min += x.first + 1;
                    temp += x.first + 1;
                }
            }
            min += x.first + 1;
        }

        return min;
    }


};

#endif