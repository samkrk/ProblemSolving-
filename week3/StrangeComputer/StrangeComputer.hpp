#ifndef STRANGECOMPUTER_HPP
#define STRANGECOMPUTER_HPP

#include <iostream>

class StrangeComputer{
public:
    int setMemory(std::string mem){
        std::vector<int> memory(mem.size(),0);
        int num_ops = 0;
        int value = 0;

        for (int i = 0 ; i < mem.size() ; i++){
            int val = mem[i] - 48;
            
            if (val != value){ // if we have a wrong bit we need to change 
                // change all bits from index i to end to !value
                value = !value;
                for (int j = i ; j < mem.size() ; j++){
                    memory.at(i) = value;
                }
                num_ops++;
            }
        }
        return num_ops;
    }

};

#endif