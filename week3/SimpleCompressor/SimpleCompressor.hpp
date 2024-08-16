#ifndef SIMPLECOMPRESSOR_HPP
#define SIMPLECOMPRESSOR_HPP

#include <iostream>
#include <string>

class SimpleCompressor{
public:
    std::string rec (std::string data, int n){
        std::string intermediate;
        std::string temp;

        int i = 2; // first two inputs are '[' and 'repeatCount' so we skip these 

        while (i < data.size()){
            // if we need to uncompress more
            if (data.at(i) == '['){
                int repeatCount = data.at(i+1) - '0'; // get repeat count 
                std::string d_substr = data.substr(i, data.size()); // remaining input 
                std::string next = rec(d_substr,repeatCount); // call function with rest of input and repeatCount
                data.erase(i,data.size() - i); // remove uncompresed part 
                data.append(next); // append new part
            }

            // if we have a character we add it to the intermediate string 
            else if (data.at(i) != ']'){
                intermediate.push_back(data.at(i));
                i++;
            }

            // else if we reach the end 
            else if (data.at(i) == ']'){
                for (int i = 0 ; i < n ; i++){
                    temp.append(intermediate);
                }
                // erase 
                data.erase(0,3+intermediate.size());
                // insert temp at front 
                data.insert(0,temp);
                break;
            }
        }
        return data;

    }

    std::string uncompress (std::string data){
        // keep looping until we see something that needs to be uncompressed 
        for (int i = 0 ; i < data.size() ; i++){
            if (data.at(i) == '['){
                int repeatCount = data.at(i+1) - '0'; // get repeat count 
                std::string d_substr = data.substr(i, data.size()); // remaining input 
                std::string next = rec(d_substr,repeatCount); // call function with rest of input and repeatCount
                data.erase(i,data.size() - i); // remove uncompresed part 
                data.append(next); // append new part 
            }
        }
        return data;
    }


};

#endif