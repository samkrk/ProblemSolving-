#ifndef UNSEALTHESAFE_HPP
#define UNSEALTHESAFE_HPP

#include <iostream>

class UnsealTheSafe{
    public:
    long recursive(int button, int N, std::vector<std::vector<long> >& memo){
        if (N == 1){
            return 1;
        }
        else if (N == 2){
            switch (button){
                case 0:
                    return 1;
                break;
                case 1:
                    return 2;
                break;
                case 2:
                    return 3;
                break;
                case 3:
                    return 2;
                break;
                case 4:
                    return 3;
                break;
                case 5:
                    return 4;
                break;
                case 6:
                    return 3;
                break;
                case 7:
                    return 3;
                break;
                case 8:
                    return 3;
                break;
                case 9:
                    return 2;
                break;
            }
        }

        // if we have the value in the memoisation matrix 
        if (memo.at(N).at(button) != -1){
            return memo.at(N).at(button);
        }

        // recursive case return all the combinations of adjacent numbers with N-1 length
        long res = 0;
        switch (button){
            case 1:
                res += recursive(2,N-1,memo);
                res += recursive(4,N-1,memo);
                memo.at(N).at(1) = res;
                return res;
            break;
            case 9:
                res += recursive(6,N-1,memo);
                res += recursive(8,N-1,memo);
                memo.at(N).at(9) = res;
                return res;
            break;
            case 2:
                res += recursive(1,N-1,memo);
                res += recursive(3,N-1,memo);
                res += recursive(5,N-1,memo);
                memo.at(N).at(2) = res;
                return res;
            break;
            case 6:
                res += recursive(3,N-1,memo);
                res += recursive(5,N-1,memo);
                res += recursive(9,N-1,memo);
                memo.at(N).at(6) = res;
                return res;
            break;
            case 4:
                res += recursive(1,N-1,memo);
                res += recursive(7,N-1,memo);
                res += recursive(5,N-1,memo);
                memo.at(N).at(4) = res;
                return res;
            break;
            case 8:
                res += recursive(9,N-1,memo);
                res += recursive(7,N-1,memo);
                res += recursive(5,N-1,memo);
                memo.at(N).at(8) = res;
                return res;
            break;
            case 3:
                res += recursive(2,N-1,memo);
                res += recursive(6,N-1,memo);
                memo.at(N).at(3) = res;
                return res;
            break;
            case 5:
                res += recursive(2,N-1,memo);
                res += recursive(4,N-1,memo);
                res += recursive(6,N-1,memo);
                res += recursive(8,N-1,memo);
                memo.at(N).at(5) = res;
                return res;
            break;
            case 7:
                res += recursive(4,N-1,memo);
                res += recursive(8,N-1,memo);
                res += recursive(0,N-1,memo);
                memo.at(N).at(7) = res;
                return res;
            break;
            case 0:
                res += recursive(7,N-1,memo);
                memo.at(N).at(0) = res;
                return res;
            break;
        }
        return res;
    }


    long countPasswords(int N){
        // Create a memoization matrix initialized to -1
        std::vector<std::vector<long> > memo(N +1 , std::vector<long> (10 , -1));

        long res = 0;
        res += recursive(0,N,memo);
        res += recursive(1,N,memo);
        res += recursive(2,N,memo);
        res += recursive(3,N,memo);
        res += recursive(4,N,memo);
        res += recursive(5,N,memo);
        res += recursive(6,N,memo);
        res += recursive(7,N,memo);
        res += recursive(8,N,memo);
        res += recursive(9,N,memo);
        
        /*
        // Display the matrix to verify
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cout << memo[i][j] << " ";
            }
            std::cout << std::endl;
        }
        */

        return res;
    }
    

};

#endif