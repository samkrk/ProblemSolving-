#ifndef CATGAME_HPP
#define CATGAME_HPP

#include <iostream>

class CatGame{
    public:

    int get_left_most(std::vector<int> coordinates){
        int min_index = 0;
        int min = 0;
        for (int i = 0 ; i < coordinates.size() ; i++){
            if (coordinates.at(i) < min){
                min_index = i;
                min = coordinates.at(i);
            }
        }
        return min_index;
    }

    int get_right_most(std::vector<int> coordinates){
        int max_index = 0;
        int max = 0;
        for (int i = 0 ; i < coordinates.size() ; i++){
            if (coordinates.at(i) > max){
                max_index = i;
                max = coordinates.at(i);
            }
        }
        return max_index;
    }

    int getNumber(std::vector<int> coordinates, int X){
        if (coordinates.size() == 1){
            return 0;
        }

        /*
        for (int i = 0 ; i < coordinates.size() ; i++){
            std::cout << coordinates.at(i) << " ";
        }
        std::cout<<std::endl;
        */


        // get right_most and left_most cats to begin with 
        int left_most_index = get_left_most(coordinates);
        int right_most_index = get_right_most(coordinates);

        int left_most = coordinates.at(left_most_index);
        int right_most = coordinates.at(right_most_index);

        int dif =  right_most - left_most;
        if (X >= dif){
            return dif;
        }

        std::vector<int> new_coords(coordinates.size() , 0);
        new_coords.at(left_most_index) = left_most + X;
        new_coords.at(right_most_index) = right_most - X;

        left_most += X;
        right_most -= X;

        // std::cout << "right_most_index: " << right_most_index << " | left_most_index: " <<  left_most_index << std::endl;

        // move all the other cats closest to left_most and right_most
        for (int i = 0 ; i < coordinates.size() ; i++){
            if (i == left_most_index || i == right_most_index){
                continue;
            }

            int current_coord = coordinates.at(i);
            int right_option = current_coord + X;
            int left_option = current_coord - X;

            if (left_option > left_most){
                new_coords.at(i) = left_option;
                continue;
            }
            if (right_option < right_most){
                new_coords.at(i) = right_option;
                continue;
            }
            
            int left_dif = std::abs(left_most - left_option);
            int right_dif = std::abs(right_most - right_option);

            if (right_dif > left_dif){
                new_coords.at(i) = left_option;
                continue;
            } else {
                new_coords.at(i) = right_option;
                continue;
            }
        }

        /*
        for (int i = 0 ; i < new_coords.size() ; i++){
            std::cout << new_coords.at(i) << " ";
        }
        std::cout<<std::endl;
        */

        int new_left_most_index = get_left_most(new_coords);
        int new_right_most_index = get_right_most(new_coords);
        return new_coords.at(new_right_most_index) - new_coords.at(new_left_most_index); 
    }


};

#endif