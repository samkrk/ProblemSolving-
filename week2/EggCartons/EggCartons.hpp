#ifndef EGGCARTONS_HPP
#define EGGCARTONS_HPP


#include <iostream>

class EggCartons{
public:
    	int minCartons(int n){
            // check n is even 
            if (n%2 != 0){
                return -1;
            }
            // check if n is a multiple of 8 
            if (n%8==0){
                return n/8;
            }
            
            // make sure n > 10 
            if (n == 10){return -1;}

            int boxes_of_six = 0;
            int temp = n;
            while (temp > 0){
                boxes_of_six++;
                temp -= 6;
                if (temp % 8 == 0){
                    return boxes_of_six+temp/8;
                }
            }
            if (temp == 0){
                return n/6;
            }
            return -1;
        }

};



#endif