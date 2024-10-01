#ifndef PROBLEMSTOSOLVE_HPP
#define PROBLEMSTOSOLVE_HPP

#include <iostream>
#include <vector>

class ProblemsToSolve{
    public:

    int minNumber(std::vector<int> pleasantness, int variety){
        // check if there are two problems with difference >= variety 
        int min = 1001;
        int max = -1;
        for (int i = 0 ; i < pleasantness.size() ; i++){
            int num = pleasantness.at(i);
            if (num < min){
                min = num;
            }
            if (num > max){
                max = num;
            }
        }
        if (max - min < variety){
            return pleasantness.size(); // must solve all problems 
        }


        // otherwise we need to use brute force 
        int min_problems = pleasantness.size();
        for (int i = 0 ; i < pleasantness.size() ; i++){
            int first_problem = pleasantness.at(i);
            for (int j = i ; j < pleasantness.size() ; j++){
                if (j == i){continue;}
                int second_problem = pleasantness.at(j);
                if (std::abs(first_problem-second_problem) >= variety){
                    int first_i_problems = (i+1)/2;
                    int i_to_j_problems = 0;
                    if ((j-i) % 2 == 0){
                        i_to_j_problems = (j-i -1)/2;
                    }
                    else if ((j - i) % 2 != 0) {
                        i_to_j_problems = (j-i)/2;
                    }
                    // std::cout << (j - i) % 2 << std::endl;
                    // std::cout << "i: " << i << " j: " << j << std::endl;
                    // std::cout << "First i: " << first_i_problems << " j to i: " << i_to_j_problems << std::endl;
                    int total_problems = first_i_problems + i_to_j_problems + 2;
                    if (total_problems < min_problems){
                        min_problems = total_problems;
                    }
                }

            }
        }
        return min_problems;

    }



};

#endif