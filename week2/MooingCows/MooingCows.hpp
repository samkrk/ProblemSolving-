#ifndef MOOINGCOWS_HPP
#define MOOINGCOWS_HPP
#include <iostream>
#include <vector>


class MooingCows{
    public:
    int dissatisfaction(std::vector<std::string> farmland){

        // initialise min dissatisfaction variable
        int min_dissatisfaction = 100000;
        int distance = 0;

        // now for each cow, calculate the dissatifaction from every other cow. 
        for (int i = 0 ; i < farmland.size() ; i++){ // rows
            for (int j = 0 ; j < farmland.at(i).size() ; j++){ // columns

            // check that we actually have a cow here 
            if (farmland.at(i).at(j) == 'C'){
                distance = 0;
                // calculate dissatisfaction 
                for (int a = 0 ; a < farmland.size() ; a++){
                    for (int b = 0 ; b < farmland.at(a).size() ; b++){
                        if (a==i && b==j){continue;}
                        // check that we actually have a cow here 
                        if (farmland.at(a).at(b) == 'C'){
                            distance += (a-i) * (a-i) + (b-j) * (b-j);
                            
                        }
                    }
                }
                if (distance < min_dissatisfaction){
                    min_dissatisfaction = distance;
    
                }
            }

            }
        }
        return min_dissatisfaction;

    }


};


#endif