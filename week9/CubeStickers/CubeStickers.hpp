#ifndef CUBESTICKERS_HPP
#define CUBESTICKERS_HPP

#include <iostream>
#include <map>

class CubeStickers{
    public:

    std::string isPossible(std::vector<std::string> sticker){
        // put everything in a map 
        std::map<std::string, int> colours;

        for (std::string colour : sticker){
            colours[colour] += 1;
        }
        
        /*
        std::cout << "All key-value pairs in the map:" << std::endl;
        for (const auto& pair : colours) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        */

        // if there are 5 or more distinct colours we can return yes 
        if (colours.size() >= 5){
            return "YES";
        }
        
        // if there are less than 3 distinct colours its impossible 
        if (colours.size() < 3){
            return "NO";
        }

        // for exactly 3 distinct colours we need there to be at least two of each colour.
        if (colours.size() == 3){
            for (const auto& pair : colours){
                if (pair.second < 2){
                    return "NO";
                }
            }
            return "YES";
        }

        // for exactly 4 distinct colours there needs to be at least two stickers of two colours 
        if (colours.size() == 4){
            int count = 0;
            for (const auto& pair : colours){
                if (pair.second >= 2){
                    count ++;
                }
            }
            if (count < 2){
                return "NO";
            } else {
                return "YES";
            }
        }
    
        // return no in default case 
        std::cout << "Error " << std::endl;
        return "NO";

    }
};


#endif