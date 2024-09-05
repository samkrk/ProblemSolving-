#ifndef NICEORUGLY_HPP
#define NICEORUGLY_HPP

#include <iostream>

class NiceOrUgly{
    public:
    bool isUgly(std::string s){
        int consonant_count = 0;
        int vowel_count = 0;
        for (int i = 0 ; i < s.size() ; i++){
            char c = s.at(i);
            if (c == '?'){
                continue;
            }
            else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){               
                consonant_count = 0;
                vowel_count ++;
                if (vowel_count == 3){
                    return true;
                }
                continue;
            }
            else {   
                vowel_count = 0;             
                consonant_count ++;
                if (consonant_count == 5){
                    return true;
                }
                continue;
            }
           
            
        }
        return false;
    }

    // try to make the word nice 
    bool makeNice(std::string s){
        std::cout << s << std::endl;
        // base case if word is ugly, return false 
        if (isUgly(s)){
            return false; // cannot make nice here 
        }

    
        // now if there are any question marks 
        int index = -1;
        for (int i = 0 ; i < s.size() ; i++){
            if (s.at(i) == '?'){
                index = i;
                break;
            }
        }
        
        if (index == -1){ // if theres no more question marks 
            return true; // word must be nice since its not ugly 
        }
        
        // in the other case, we have a question mark so we need to 
        // determine if we can make it nice still
        s.at(index) = 'A';
        if (makeNice(s)){
            return true;
        }

        s.at(index) = 'Z';
        if (makeNice(s)){
            return true;
        }

        return false;
    }

    std::string describe(std::string s){       
        // if the word is ugly with the question marks then it can never be NICE 
        if (isUgly(s)){
            return "UGLY";
        }
        // try to make it ugly by stuffing consonants 
        std::string temp = s;
        for (int i = 0 ; i < temp.size() ; i++){
            if (temp.at(i) == '?'){
                temp.at(i) = 'Z';
            }
        }
        bool ugly = isUgly(temp);
        // std::cout << "Ugly? " << ugly << std::endl;

        // if stuffing it with consonants didn't work, try using vowels 
        if (!ugly){
            temp = s;
            for (int i = 0 ; i < temp.size() ; i++){
                if (temp.at(i) == '?'){
                    temp.at(i) = 'A';
                }
            }
            ugly = isUgly(temp);
            // std::cout << "Ugly? " << ugly << std::endl;

        }
        
        // now try to make it NICE 
        bool nice = makeNice(s);
        // std::cout << "Nice? " << nice << std::endl;

        if (nice && ugly){
            return "42";
        }
        else if(nice){
            return "NICE";
        }
        else {
            return "UGLY";
        }
    }


};

#endif