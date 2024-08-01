#ifndef AZIMUTHMONITORING_HPP
#define AZIMUTHMONITORING_HPP

#include <iostream>
#include <sstream>
#include <vector>

class AzimuthMonitoring{
public:
    int getAzimuth(std::vector<std::string> instructions){

        int dir = 0;

        for (const auto& instruction: instructions){
            if (instruction == "HALT"){
                break;
            }

            else if (instruction == "RIGHT"){
                dir += 90;
            }
            else if (instruction == "LEFT"){
                dir -= 90;
            }
            else if (instruction == "TURN AROUND"){
                dir += 180;
            }
            else if (instruction.find("RIGHT ") == 0) {
                int degrees = std::stoi(instruction.substr(6)); // Extract the number after "RIGHT "
                dir += degrees;
            }
            else if (instruction.find("LEFT ") == 0) {
                int degrees = std::stoi(instruction.substr(5)); // Extract the number after "LEFT "
                dir -= degrees;
            }
            
        // Normalize dir to be in the range [0, 360)
        dir = (dir % 360 + 360) % 360;
        }

    
        return dir;
    }
};



#endif