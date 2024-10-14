#ifndef CATGAME_HPP
#define CATGAME_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class CatGame{
    public:

    int get_left_most(std::vector<int> coordinates){        
        long min = 1000000000;
        for (int i = 0 ; i < coordinates.size() ; i++){
            if (coordinates.at(i) < min){                
                min = coordinates.at(i);
            }
        }
        return min;
    }

    int get_right_most(std::vector<int> coordinates){
        long max = -1000000000;
        for (int i = 0 ; i < coordinates.size() ; i++){
            if (coordinates.at(i) > max){            
                max = coordinates.at(i);
            }
        }
        return max;
    }

    int getNumber(std::vector<int> coordinates, int X){
        if (coordinates.size() == 1){
            return 0;
        }

        // sort the array first
        std::vector<int> coords = coordinates;
        std::sort(coords.begin(), coords.end());

        // if X is greater than right_most - left_most then we will move everything one direction anyway
        if (coords.back() - coords.front() <= X){
            return coords.back() - coords.front();
        }

        long min_dif = 10000000001;
        long dif = 0;
        std::vector<int> temp(coords.size() ,0);

        // Move everything to the left to begin with. 
        for (int i = 0 ; i < temp.size() ; i++){
            temp.at(i) = coords.at(i) - X;
        }
        
        // move one more cat to the right 
        for (int i = 0 ; i < coords.size() ; i++){
            temp.at(i) += 2*X;

            dif = get_right_most(temp) - get_left_most(temp);
            
            if (dif < min_dif){
                min_dif = dif;
            }
        }
        return min_dif;
    }


};

#endif