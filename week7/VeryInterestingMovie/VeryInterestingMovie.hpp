#ifndef VERYINTERESTINGMOVE_HPP
#define VERYINTERESTINGMOVE_HPP

#include <iostream>

class VeryInterestingMovie{
    public:

    int maximumPupils (std::vector<std::string> seats){
        int count = 0;

        for (int i = 0 ; i < seats.size() ; i++){ // each row
            for (int s = 0 ; s < seats.at(i).size() ; s++){ // each seat 
                if (seats.at(i).at(s) == 'Y'){
                    count++;
                    if (s < seats.at(i).size() - 1){ // dont worry about adjacent in last seat 
                        seats.at(i).at(s+1) = 'N'; // update adjacent seat 
                    }
                }
            }

        }
        return count;
    }

};

#endif