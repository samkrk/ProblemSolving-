#ifndef TIMETRAVELLINGCELLAR_HPP
#define TIMETRAVELLINGCELLAR_HPP

#include <iostream>

class TimeTravellingCellar{
    public:
    int determineProfit(std::vector<int> profit, std::vector<int> decay){
        // find max profit
        int max = -1;
        int max_index = 0;
        for (int i = 0 ; i < profit.size() ; i++){
            if (profit.at(i) > max){
                max = profit.at(i);
                max_index = i;
            }
        }
        // find second largest profit 
        int second_max = -1;
        int second_index = 0;
        for (int i = 0 ; i < profit.size() ; i++){
            if (profit.at(i) > second_max){
                if (i != max_index){
                    second_max = profit.at(i);
                    second_index = i;
                }
            }
        }

        
        // find min decay 
        int min = max;
        for (int j = 0 ; j < decay.size() ; j++){
            // std::cout << j << std::endl;
            if (j == max_index){
                continue;
            }
            if (decay.at(j) < min){
                min = decay.at(j);
            }
        }
        // std::cout << "Min: " << min << std::endl;
        if (profit.at(second_index) - decay.at(max_index) > max-min){
            return profit.at(second_index) - decay.at(max_index);
        }
        else {
            return max-min;
        }
    }

};


#endif 