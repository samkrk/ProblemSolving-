#ifndef ELEVATORLIMIT_HPP
#define ELEVATORLIMIT_HPP

#include <iostream>
#include <vector>

class ElevatorLimit{
    public:
    std::vector<int> getRange(std::vector<int> enter, std::vector<int> exit, int physicalLimit){
        std::vector<int> res;
        
        int max = -10000;
        int min = 10000;

        int tally = 0;
        for (int i = 0 ; i < enter.size() ; i++){
            tally -= exit.at(i);
            if (tally < min){
                min = tally;
            }
            tally += enter.at(i);
            if (tally > max){
                max = tally;
            }
        }

        max = physicalLimit - max;
        // if max < 0, we have exceeded elevator limit. 
        if (max < 0){
            return res;
        }

        if (min < 0){
            res.push_back(-min);
            res.push_back(max);
            return res;
        }
        else {
            res.push_back(0);
            res.push_back(max);
            return res;
        }
    }

};


#endif