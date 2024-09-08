#ifndef TALILULUCOFFEE_HPP
#define TALILULUCOFFEE_HPP

#include <iostream>
#include <algorithm>

class TaliluluCoffee{
    public:

    int maxTip(std::vector<int> tips){
        if (tips.empty()){
            return 0;
        }
        int total_tips = 0;

        // initialise profit and loss vector
        std::vector<int> pnl (tips.size() , 0);
        
        while (true){
            // calculate pnl 
            for (int i = 0 ;i < tips.size() ; i++){
                pnl.at(i) = tips.at(i);
            }

            // find the max pnl and add to total 
            int max = -10000000;
            int index = -1;
            for (int i = 0 ; i < pnl.size() ; i++){
                if (pnl.at(i) > max){
                    max = pnl.at(i);
                    index = i;
                }
            }
            // add max pnl to total_tips 
            if (max <= 0 || index == -1){
                break;
            }

            total_tips += tips.at(index);
            // remove customer by making their tip negative 
            tips.at(index) = -1;

            // reduce all other tips by 1 
            for (int i = 0 ;i < tips.size() ; i++){
                if (tips.at(i) > 0){
                    tips.at(i) = tips.at(i) -1;
                }
            }        
        }
        return total_tips;
    }
};

#endif