#ifndef THROWTHEBALL_HPP
#define THROWTHEBALL_HPP

#include <iostream>
#include <cmath>
#include <vector>

class ThrowTheBall{
    public:
    int timesThrown(int N, int M, int L){
        // initialise player vector 
        std::vector<int> players(N, 0);
        players.at(0) = 1; // player 1 starts by recieving the ball
        int res = 0;

        // pass the ball 
        int pass_index = 0;

        while (players.at(pass_index) < M){
        
        if (players.at(pass_index) % 2 == 0){ // number is even so ball goes to the left 
            pass_index = (pass_index+ L)%N;
        }
        else{
            pass_index = (pass_index- L + N)%N;
        }
        players.at(pass_index)++; // increment p 
        res++;
        
        }
        
        return res;
    }
};

#endif