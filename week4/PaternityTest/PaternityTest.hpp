#ifndef PATERNITYTEST_HPP
#define PATERNITYTEST_HPP

#include <iostream>
#include <string>

class PaternityTest{
    public:
    std::vector<int> possibleFathers(std::string child, std::string mother, std::vector<std::string> men){
        std::vector<std::string> potential_fathers; // fathers with at least half the DNA of the child 
        std::vector<int> potential_fathers_index; // list of the indexes of the potential fathers in the men array 
        std::vector<int> possible; // final result vector 
        std::vector<int> missing_indexes; // missing DNA indexes with child and mother 
        int not_the_father = 0;
        
        // First find a list of potential fathers with half the DNA as the child 
        for (int i = 0 ; i < men.size() ; i++){ // loop through all the men 
            int count = 0; 
            for (int j = 0 ; j < men.at(i).size() ; j++){
                if (men.at(i).at(j) == child.at(j)){ // if they have a matching DNA index 
                    count++;
                }
            }
            if (count >= child.size()/2){
                potential_fathers.push_back(men.at(i));
                potential_fathers_index.push_back(i);
            }
        }
        

        // loop through mother array and find missing indexes with child 
        for (int i = 0 ; i < mother.size() ; i++){
            if (mother.at(i) != child.at(i)){
                missing_indexes.push_back(i);
            }
        }
      

        // loop through the list of men 
        for (int i = 0 ; i < potential_fathers.size() ; i++){
            not_the_father = 0;
            // loop through the missing indexes 
            for (int j = 0 ; j < missing_indexes.size() ; j++){
                if (potential_fathers.at(i).at(missing_indexes.at(j)) != child.at(missing_indexes.at(j))){
                    not_the_father = 1;
                    break;
                }
            }
            if (not_the_father){
                continue;
            }
            else {
                possible.push_back(potential_fathers_index.at(i));
            }
        }
        return possible;
    }


};


#endif