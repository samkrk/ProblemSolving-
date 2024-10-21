#ifndef BIGBURGER_HPP
#define BIGBURGER_HPP

#include <iostream>
#include <queue>


class BigBurger{
    public:

    int maxWait(std::vector<int> arrival, std::vector<int> service){
        // init variables and queues 
        int time = arrival.at(0) + service.at(0); 
        int max_wait = 0;
        
        
        for (int i = 1 ; i < arrival.size() ; i++){
            int curr_wait = time - arrival.at(i);

            if (curr_wait <= 0){ // customer did not have to wait 
                time = arrival.at(i) + service.at(i);
            } else { // costumer did have to wait 
                if (curr_wait > max_wait){
                    max_wait = curr_wait;
                }
                time += service.at(i);
            }

        }

        return max_wait;

    }


};

#endif