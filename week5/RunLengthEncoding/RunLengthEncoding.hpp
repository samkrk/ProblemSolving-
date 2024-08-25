#ifndef RUNELENGTHENCODING_HPP
#define RUNELENGTHENCODING_HPP

#include <iostream>

class RunLengthEncoding{
    public:

    // Find number returns the number n, and the index i to continue the algorithm.
    std::vector<int> findNumber(std::string text, int i){ // number at i in string is an integer. 
            int n = text.at(i) - '0';
            int index = 1;
            while (true){
                
                if (text.at(index + i) <= '9'){
                    n *= 10;
                    n += text.at(index + i) - '0';
                    index++;
                }
                if (n > 50){
                    break;
                }
                else if (text.at(index + i) > '9'){
                    break;
                }
            }
            // first element in vector is the number 
            // second element is the index of the letter 
            std::vector<int> r;
            r.push_back(n);
            r.push_back(index + i);
            return r;
    }

    std::string decode(std::string text){
        std::string result;

        for (int i = 0 ; i < text.size() ; i++){
            
            if (text.at(i) <= '9'){ // if we have a number 
                std::vector<int> temp = findNumber(text, i);
                
                if (temp.at(0) > 50){
                    return "TOO LONG";
                }
                else {
                    std::string word (temp.at(0), text.at(temp.at(1)));
                    result.append(word);
                    i = temp.at(1) ;
                }
            }
            else{ // if we just have a letter
                result.push_back(text.at(i));
            }

            // if we exceed 50 characters
            if (result.size() > 50){
            return "TOO LONG";
            }
        }
        

        return result;
    }



};

#endif