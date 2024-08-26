#ifndef HOUSEBUILDING_HPP
#define HOUSEBUILDING_HPP

#include <iostream>

class HouseBuilding{
    public:

    int getMinimum(std::vector<std::string> area){
        // get occurances of each digit
        std::vector<int> digits (10 , 0);
         
        for (int i = 0 ; i < area.size() ; i++){
            for (int j = 0 ; j < area.at(i).size() ; j++){
                int element = area.at(i).at(j) - '0';
                digits.at(element)++;
            }
        }

        // try all pairs of levels 
        std::vector<int> level_pairs;
        int base = 0;
        for (int k = 0 ; k < 9 ; k++){
            int effort = 0;
            for (int i = 0 ; i < digits.size() ; i++){
                if (i == base || i == base + 1){
                    continue;
                }
                if (i < base){
                    effort += (base - i) * digits.at(i); // height differnce * number of occurances 
                }
                else if (i > base + 1){
                    effort += (i - base - 1) * digits.at(i);
                }
            }
            level_pairs.push_back(effort);
            base++;
        }
    
        // return minimum of the efforts 
        int min_effort = 2147483600;
        for (int i = 0 ; i < level_pairs.size() ; i++){
            if (level_pairs.at(i) < min_effort){
                min_effort = level_pairs.at(i);
            }
        }
        return min_effort;
    }
};

#endif