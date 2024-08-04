#ifndef ELEVATORLIMIT_HPP
#define ELEVATORLIMIT_HPP

#include <iostream>
#include <vector>

class ElevatorLimit{
    public:
    std::vector<int> getRange(std::vector<int> enter, std::vector<int> exit, int physicalLimit){
        std::vector<int> res;
        
        int max = physicalLimit;
        int min = 0;

        int tally = 0;
        for (int i = 0 ; i < enter.size() ; i++){
            if (enter.at(i)>physicalLimit){return res;}
            if (exit.at(i)>physicalLimit){return res;}
            // people leave 
            tally -= exit.at(i);
            if (tally < min){
                min = tally;
            }
            if(-min > physicalLimit){
                return res;
            }
            // people enter 
            tally += enter.at(i);
            if (tally > 0 && physicalLimit-tally < max){
                max = physicalLimit-tally;
            }
            if(max > physicalLimit){
                return res;
            }
        }

        if (min < 0){
            if (-min > max){ return res;}
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