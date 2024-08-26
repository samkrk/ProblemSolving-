#ifndef RGBSTREET_HPP
#define RGBSTREET_HPP

#include <iostream>
#include <sstream>

class RGBStreet{
    public:
    std::vector<std::vector<int> > getPrices(const std::vector<std::string>& inputStrings) {
        std::vector<std::vector<int> > result;

        for (size_t i = 0; i < inputStrings.size(); ++i) { 
            std::vector<int> row;
            std::stringstream ss(inputStrings[i]);
            std::string temp;

            while (ss >> temp) {
                row.push_back(std::stoi(temp)); // Convert each substring to an integer
            }

            result.push_back(row);
        }

        return result;
    }
    
    int findCheapest(std::vector<int> house, int previousColour){
        switch (previousColour){
            case 0: // red
                if (house.at(1) > house.at(2)){
                    return 2;
                }
                else {
                    return 1;
                }
                break;
            case 1: // green
                if (house.at(0) > house.at(2)){
                    return 2;
                }
                else {
                    return 0;
                }
                break;
            case 2: // blue 
                if (house.at(0) > house.at(1)){
                    return 1;
                }
                else {
                    return 0;
                }
                break;
        }
        std::cout << "Exception" << std::endl;
        return -1;
    }


    int rec(std::vector<std::vector<int> > houses, int previousColour, int i){
        int index = i;
        // base case there is only one house left 
        if (index == houses.size()-1){
            
            // return cheapest possible house 
            int colour = findCheapest(houses.at(index), previousColour);
            return houses.at(index).at(colour);
        }

        // recursive case, try both other colours 
        int first_case = 0;
        int second_case = 0;
        switch (previousColour){
            case 0: // previous house was red 
                first_case = houses.at(index).at(1) + rec(houses,1,index+1); // try green house 
                second_case = houses.at(index).at(2) + rec(houses,2,index+1); // try blue house 
                // return cheapest cost 
                if (first_case > second_case){
                    return second_case;
                }
                else{
                    return first_case;
                }
                break;
            case 1: // previous colour was green 
                first_case = houses.at(index).at(0) + rec(houses,0,index+1); // try red house 
                second_case = houses.at(index).at(2) + rec(houses,2,index+1); // try blue house 
                // return cheapest cost 
                if (first_case > second_case){
                    return second_case;
                }
                else{
                    return first_case;
                }
                break;

            case 2: // previous colour was blue 
                first_case = houses.at(index).at(0) + rec(houses,0,index+1); // try red house 
                second_case = houses.at(index).at(1) + rec(houses,1,index+1); // try green house 
                // return cheapest cost 
                if (first_case > second_case){
                    return second_case;
                }
                else{
                    return first_case;
                }
                break;
            default:
                std::cout << "Rec function failed" << std::endl;
                break;
        }
        std::cout << "Exception in rec" << std::endl;
        return -1;
    }

    int estimateCost(std::vector<std::string> houses){
        // first get prices in matrix format for ease of access/operations
        std::vector<std::vector<int> > matrix = getPrices(houses);

        // print matrix for debugging 
        /*
        for (int i = 0 ; i  < matrix.size() ; i++){
            for (int j = 0 ; j < matrix.at(i).size() ; j++){
                std::cout << matrix.at(i).at(j) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        */

        // now try all three colours for the first house and choose cheapest one for answer 
        int red = matrix.at(0).at(0) + rec(matrix , 0 , 1);
        int green = matrix.at(0).at(1) + rec(matrix , 1 , 1);
        int blue = matrix.at(0).at(2) + rec(matrix , 2 , 1);

        /*
        std::cout << "red house cost: " << red << std::endl;
        std::cout << "green house cost: " << green << std::endl;
        std::cout << "blue house cost: " << blue << std::endl;
        */


        if (red <= green){
            if (red <= blue){
                return red;
            }
            else{
                return blue;
            }
        }
        else if (green <= blue){
            return green;
        }
        else {
            return blue;
        }

    }

    

};

#endif