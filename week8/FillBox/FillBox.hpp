#ifndef FILLBOX_HPP
#define FILLBOX_HPP

#include <iostream>
#include <vector>
#include <cmath>

class FillBox{
    public:

    int minCubes(int length, int width, int height, std::vector<int> cubes){
        std::vector<int> ideal = findIdeal(length,width,height);        
        return numCubes(ideal,cubes);
    }

    int numCubes(std::vector<int> ideal, std::vector<int> cubes){
        // zero extend cubes 
        std::vector<int> available(20,0);
        for (int i = 0 ; i < cubes.size() ; i++){
            available.at(i) = cubes.at(i);
        }

        
        std::cout << "Ideal: ";
        for (auto i : ideal){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "Available: ";
        for (auto i : available){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        

        int total = 0;
        // loop through and calculate the difference 
        for (int i = 19 ; i >= 0 ; i--){   
            if (total < 0){return -1;}         
            if (ideal.at(i) <= available.at(i)){
                total += ideal.at(i);                
            }
            else {
                total += available.at(i);                
                int diff = ideal.at(i) - available.at(i);                
                if (i == 0){
                    return -1; // impossible case 
                }
                else {
                    ideal.at(i-1) += 8*diff;                    
                }
            }
        }
        if (total <= 0){
            return -1;
        }
        return total;
    }


    std::vector<int> findIdeal(int length, int width, int height){
        std::vector<int> powers = getPowers();
        std::vector<int> goals = largestPowers(length,width,height, powers);

        if (length == 1 || width == 1 || height == 1){
            std::vector<int> res(20,0);
            res.at(0) = length*width*height;
            return res;
        }

        std::vector<int> res(20,0);
        std::vector<int> temp;
        if (length-goals.at(0) != 0){
            temp = findIdeal(length-goals.at(0),width,height);
            for (int i = 0 ; i < res.size() ; i++){
                res.at(i) += temp.at(i);}
        }
        if (width-goals.at(1) != 0){
            temp = findIdeal(goals.at(0),width-goals.at(1),height);
            for (int i = 0 ; i < res.size() ; i++){
                res.at(i) += temp.at(i);}
        }
        if (height-goals.at(2) != 0){    
            temp = findIdeal(goals.at(0),goals.at(1),height-goals.at(2));
            for (int i = 0 ; i < res.size() ; i++){
                res.at(i) += temp.at(i);}
        }

        temp = bigBox(goals.at(0),goals.at(1),goals.at(2));
        for (int i = 0 ; i < res.size() ; i++){
            res.at(i) += temp.at(i);}
        return res;
    }

    std::vector<int> bigBox(int length, int width, int height){
        std::vector<int> res(20,0);
        if (length == width == height){
            int index = log(length) / log(2);
            res.at(index) += 1;
            return res;
        }
        else {
            int min = std::min(length,width);
            min = std::min(min,height);

            int numInstances = length/min;
            numInstances *= width/min;
            numInstances *= height/min;

            int index = log(min) / log(2);

            res.at(index) += numInstances;
            return res;
        }        
    }


    std::vector<int> getPowers(){
        std::vector<int> res;
        for (int i = 0 ; i <= 20 ; i++){
            int num = pow(2,i);
            res.push_back(num);
        }
        return res;
    }

    std::vector<int> largestPowers(int length, int width, int height, std::vector<int> powers){
        int lpower;
        int wpower;
        int hpower;
        for (auto i : powers){
            if (i  > length){
                lpower  = i/2;
                break;
            }
        }
        for (auto i : powers){
            if (i  > width){
                wpower  = i/2;
                break;
            }
        }
        for (auto i : powers){
            if (i  > height){
                hpower  = i/2;
                break;
            }
        }
        std::vector<int> res;
        res.push_back(lpower);
        res.push_back(wpower);
        res.push_back(hpower);
        return res;
    }

};

#endif