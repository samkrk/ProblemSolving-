#ifndef LOSTPARENTHESES_HPP
#define LOSTPARENTHESES_HPP

#include <iostream>
#include <regex>

class LostParentheses{
    public:

    // Function to convert the entire string to a list of integers based on signs
    std::vector<int> stringToInt(const std::string& s) {
        std::vector<int> res;

        // Define regex pattern to match numbers with optional + or - sign
        std::regex pattern(R"([+-]?\d+)");
        std::sregex_iterator it(s.begin(), s.end(), pattern);
        std::sregex_iterator end;

        // Iterate through all matches
        while (it != end) {
            // Convert the matched string to an integer and add to the result vector
            res.push_back(std::stoi(it->str()));
            ++it;
        }
        return res;
    }
    

    int minResult(std::string e){

        std::vector<int> nums = stringToInt(e);

        int sum = 0; 
        bool in_brackets = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            int num = nums.at(i);
            if (num > 0){
                if (in_brackets){
                    sum -= num;
                }
                else {
                    sum += num;
                }
            }
            else {
                if (in_brackets){
                    sum += num;
                }
                else {
                    in_brackets = true;
                    sum += num;
                }
            }
        }

        return sum;
    }



};


#endif