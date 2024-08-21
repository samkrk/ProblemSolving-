#ifndef MONSTERSVALLEY2
#define MONSTERSVALLEY2

#include <iostream>

class MonstersValley2{
    public:

    int rec(std::vector<int> dread, std::vector<int> price, int scariness){
        // initialise cost variable to return 
        int cost = 0;

        // base case where we only have one monster left 
        if (dread.size() == 1){
            // check if we need to buy it 
            if (dread.at(0) > scariness){
                return price.at(0);
            }
            else {
                return cost;
            }
        }
        
        // while we have to bribe the next monster 
        int must_bribe = 1;
        int index = 0;
        while (must_bribe){
            // if we have to bribe the next monster
            if (dread.at(index) > scariness){
                scariness += dread.at(index);
                cost += price.at(index);
            }
            // if we can walk past the monster 
            else {
                must_bribe = 0;
            }
        }

        // now we have the choice to bribe or walk past a monster 
        std::vector<int> remaining_dread (dread.begin() + index + 1, dread.end());
        std::vector<int> remaining_price (price.begin() + index + 1, price.end());

        // walk past option 
        int walk = cost + rec(remaining_dread,remaining_price,scariness);

        // bribe option 
        scariness += dread.at(index);
        int bribe = cost + price.at(index) + rec(remaining_dread,remaining_price,scariness);

        // return the smallest of the two costs 
        if (walk < bribe){
            return walk;
        }
        else {
            return bribe;
        }
    }
    


    int minimumPrice(std::vector<int> dread, std::vector<int> price){
        int scariness = dread.at(0); // must bribe first monster 
        int cost = price.at(0); 

        std::vector<int> remaining_dread (dread.begin() + 1, dread.end());
        std::vector<int> remaining_price (price.begin() + 1, price.end());
        
        return cost + rec(dread,price,scariness);
    }


};


#endif