#ifndef TIMETRAVELLINGCELLAR_HPP
#define TIMETRAVELLINGCELLAR_HPP

#include <iostream>

class TimeTravellingCellar{
    public:
    int determineProfit(std::vector<int> profit, std::vector<int> decay){
        // find max profit
        int max = profit.at(0);
        int max_index = 0;
        for (int i = 0 ; i < profit.size() ; i++){
            if (profit.at(i) > max){
                max = profit.at(i);
                max_index = i;
            }
        }
        // std::cout << "Max: " << max << std::endl;

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
        return max-min;
    }

};


#endif 