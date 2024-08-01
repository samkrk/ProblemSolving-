#ifndef DOWNLOADINGFILES_HPP
#define DOWNLOADINGFILES_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class DownloadingFiles{
public: 
    void splitVector(const std::vector<std::string>& input, std::vector<double>& speed, std::vector<double>& t) {
    for (const auto& str : input) {
        std::istringstream iss(str);
        double first, second;
        iss >> first >> second; // Read the two integers from the string
        speed.push_back(first);
        t.push_back(second);
    }
}
    double actualTime(std::vector<std::string> tasks){
        std::vector<double> speed;
        std::vector<double> t;

        splitVector(tasks,speed,t);

        int length = speed.size();

        double res = 0;
        
        for (int i = 0 ; i < length ; i++){
            // put element closest to downloading at the start 
            double min = t.at(i); 
            for (int k = i ; k < length ; k++){
                if (t.at(k) < t.at(i)){
                    size_t index1 = i; 
                    size_t index2 = k; 
                
                    std::swap(t[index1], t[index2]);
                    std::swap(speed[index1], speed[index2]);
                }
            }

            res += t.at(i); 
            // if we have reached the last element, break 
            if (i == length-1){
                break;
            }
            
            // subtract time 
            double lost_time = t.at(i);
            for (int j = i ; j < length ; j++){
                t.at(j) -= lost_time;
            }

            // change speed 
            speed.at(i+1) += speed.at(i);

            // recalculate time for i+1 
            t.at(i+1) = t.at(i+1)*(speed.at(i+1)-speed.at(i))/speed.at(i+1);

        }

        return res;
    }
};


#endif