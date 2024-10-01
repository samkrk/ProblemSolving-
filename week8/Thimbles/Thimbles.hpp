#ifndef THIMBLES_HPP
#define THIMBLES_HPP    

#include <iostream>
#include <vector>

class Thimbles{
public:

    int thimbleWithBall(std::vector<std::string> swaps){
        int pos = 1;

        for (int i = 0 ; i < swaps.size() ; i++){
            int first = swaps.at(i).at(0)-48;
            int second = swaps.at(i).at(2)-48;

            if (first == pos){
                pos = second;
                continue;
            }
            else if (second == pos){
                pos = first;
                continue;
            }
        }

        return pos;
    }

};


#endif