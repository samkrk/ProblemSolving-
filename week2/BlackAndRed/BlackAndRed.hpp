#ifndef BLACKANDRED_HPP
#define BLACKANDRED_HPP

#include <iostream>

class BlackAndRed{
public:
    int cut(std::string deck){
        // initialise red and black counter, along with index variable
        int r = 0, b = 0, i = 0;


        int found_index = false;

        while (found_index == false){
            r = 0;
            b = 0;

            // if current index is a red, try next index
            if (deck[i] == 'R'){
                i++;
                continue;
            }
            
            // check the rest of the string to see if it works 
            for (int k = i ; k < deck.size() ; k++){
                if (deck[k] == 'R'){r++;}
                else {b++;}

                // if at any point r>b, break the loop and try again from index i 
                if (r > b){
                    i = k+1;
                    break;
                }

                // if we reach the end of the deck, we have found our answer 
                if (k == deck.size()-1){
                    found_index = true;
                }
            }
        }
        return i;
    }


};

#endif