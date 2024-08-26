#ifndef HOUSEBUILDING_HPP
#define HOUSEBUILDING_HPP

#include <iostream>

class HouseBuilding{
    public:

    int getMinimum(std::vector<std::string> area){
        // get occurances of each digit
        std::vector<int> digits (10 , 0);
         
        for (int i = 0 ; i < area.size() ; i++){
            for (int j = 0 ; j < area.at(i).size() ; j++){
                int element = area.at(i).at(j) - '0';
                digits.at(element)++;
            }
        }

        // get average 
        int sum = 0;
        for (int i = 0 ; i < digits.size() ; i++){
            sum += digits.at(i)*i;
        }
        int avg = sum/(area.size()*area.at(0).size());
    

        // try levels at (avg-1,avg) 
        int effort = 0;
        switch (avg){
            case 0: // cannot do levels (-1, 0) so just skip, levels (0,1) will be less effort always
                effort = INT_MAX;
                break;
            default:
            for (int i = 0 ; i < digits.size() ; i++){
                if (i == avg - 1 || i == avg){
                    continue;
                }
                if (i < avg - 1){
                    effort += (avg - 1 - i) * digits.at(i); // height differnce * number of occurances 
                }
                else if (i > avg){
                    effort += (i - avg) * digits.at(i);
                }       
            }
            break;
        }
        int first_case = effort;

        // (avg, avg+1) case 
        effort = 0;
        switch (avg){
            case 9: // cannot do levels (9,10) so levels (8,9) will always be less effort
                effort = INT_MAX;
            default:
            for (int i = 0 ; i < digits.size() ; i++){
                if (i == avg || i == avg + 1){
                    continue;
                }
                if (i < avg){
                    effort += (avg - i) * digits.at(i); // height differnce * number of occurances 
                }
                else if (i > avg + 1){
                    effort += (i - avg - 1) * digits.at(i);
                }
                
            }
            break;

        }

        // debug printing 
        /*
        std::cout << "First case " << first_case << std::endl;
        std::cout << "Second case " << effort << std::endl;
        */

        // return minimum of the two efforts 
        if (first_case > effort){
            return effort;
        }
        else {
            return first_case;
        }

    }




};

#endif