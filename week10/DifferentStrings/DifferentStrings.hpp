#ifndef DIFFERENTSTRINGS_HPP
#define DIFFERENTSTRINGS_HPP

#include <iostream>

class DifferentStrings{
    public:
    // returns the number of different characters in the two strings 
    // starts comparing A to B at index i.
    int count_diff(std::string A, std::string B, int index){
        if (index + A.size() > B.size()){
            std::cout << "Indexing error about to happen" << std::endl;
            return -1;
        }
        
        int diff = 0;
        for (int i = 0 ; i < A.size() ; i++){
            if (A.at(i) != B.at(index + i)){
                diff++;
            }
        }
        return diff;
    }

    int minimize(std::string A, std::string B){
        if (A.size() == B.size()){
            return count_diff(A,B,0);
        }

        int min_diff = 10000;
        int length_diff = B.size() - A.size(); 
        for (int i = 0 ; i <= length_diff ; i++){
            int curr_diff = count_diff(A,B,i);
            if (curr_diff < min_diff){
                min_diff = curr_diff;
            }
        }
        return min_diff;
    }


};

#endif