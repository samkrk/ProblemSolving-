#ifndef MONSTERSVALLEY2
#define MONSTERSVALLEY2

#include <iostream>



class MonstersValley2{
    public:

    int rec(std::vector<int> dread, std::vector<int> price, int scariness){
        // initialise cost variable to return 
        int cost = 0;
        int curr_scariness = scariness;
        /*
        std::cout << "Remaining monsters: ";
        for (int i = 0 ; i < dread.size() ; i++){
            std::cout << dread.at(i) << " ";
        }
        std::cout << std::endl;
        std::cout << "Remaining cost: ";
        for (int i = 0 ; i < price.size() ; i++){
            std::cout << price.at(i) << " ";
        }
        std::cout << std::endl;
        */
        // base case where we only have one monster left 
        if (dread.size() == 1){
            // check if we need to buy it 
            if (dread.at(0) > curr_scariness){
                return cost + price.at(0);
            }
            else {
                return cost;
            }
        }

        
        // while we have to bribe the next monster 
        bool must_bribe = 1;
        int index = 0;
        bool in_bounds = 1;
        while (must_bribe && in_bounds){
            /*
            std::cout << "Dread.size() - index = " << dread.size() - index << std::endl;
            std::cout << "Current scariness: " << curr_scariness << std::endl;
            std::cout << "Current cost: " << cost << std::endl;
            */
            // if we are in bounds 
            if (index == dread.size()){ // if there are no monsters left 
                return cost;
                break;
            }
            // if we have to bribe the next monster
            else if (dread.at(index) > curr_scariness){
                curr_scariness += dread.at(index);
                cost += price.at(index);
                if (curr_scariness > 2000000000 || curr_scariness < 0){
                    return cost;
                }
                index++;
            }
            // if we can walk past the monster 
            else {
                must_bribe = 0;
                break;
            }
        }

        // base case where we only have one monster left 
        if (dread.size() - index == 1){
            // check if we need to buy it 
            if (dread.at(index) > curr_scariness){
                return cost + price.at(index);
            }
            else {
                return cost;
            }
        }

        // now we have the choice to bribe or walk past a monster 
        std::vector<int> remaining_dread (dread.begin() + index + 1, dread.end());
        std::vector<int> remaining_price (price.begin() + index + 1, price.end());

        // walk past option 
        int walk = cost + rec(remaining_dread,remaining_price,curr_scariness);

        // bribe option 
        curr_scariness += dread.at(index);
        int bribe = cost + price.at(index) + rec(remaining_dread,remaining_price,curr_scariness);

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
        
        return cost + rec(remaining_dread,remaining_price,scariness);
    }


};


#endif