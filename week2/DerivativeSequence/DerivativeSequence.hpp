#ifndef DERIVATIVESEQUENCE_HPP
#define DERIVATIVESEQUENCE_HPP

#include <iostream>
#include <vector>

class DerivativeSequence{
public: 
std::vector<int> derSeq(std::vector<int> a, int n){
    // initialise temp and next derivative vector 
    std::vector<int> temp = a;
    std::vector<int> next_der;

    // outer loop for nth derivative 
    for (int i = 0 ; i < n ; i++){

        // inner loop for calculating the derivative
        for (int k = 0 ; k < a.size() - i - 1 ; k++){
            next_der.push_back(temp.at(k+1) - temp.at(k));
        }
        // set temp to next_der;
        temp = next_der;
        // reset next_der
        next_der.clear();
    }
    return temp;
}



};


#endif