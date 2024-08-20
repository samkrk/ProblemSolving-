#ifndef UNSEALTHESAFE_HPP
#define UNSEALTHESAFE_HPP

#include <iostream>

class UnsealTheSafe{
    public:
    long recursive(int button, int N){
        long res = 0;
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

        // recursive case return all the combinations of adjacent numbers with N-1 length
        else {
            switch (button){
                case 1:
                    res += recursive(2,N-1);
                    res += recursive(4,N-1);
                    return res;
                break;
                case 9:
                    res += recursive(2,N-1);
                    res += recursive(4,N-1);
                    return res;
                break;
                case 2:
                    res += recursive(1,N-1);
                    res += recursive(3,N-1);
                    res += recursive(5,N-1);
                    return res;
                break;
                case 6:
                    res += recursive(1,N-1);
                    res += recursive(3,N-1);
                    res += recursive(5,N-1);
                    return res;
                break;
                case 4:
                    res += recursive(1,N-1);
                    res += recursive(7,N-1);
                    res += recursive(5,N-1);
                    return res;
                break;
                case 8:
                    res += recursive(1,N-1);
                    res += recursive(7,N-1);
                    res += recursive(5,N-1);
                    return res;
                break;
                case 3:
                    res += recursive(2,N-1);
                    res += recursive(6,N-1);
                    return res;
                break;
                case 5:
                    res += recursive(2,N-1);
                    res += recursive(4,N-1);
                    res += recursive(6,N-1);
                    res += recursive(8,N-1);
                    return res;
                break;
                case 7:
                    res += recursive(4,N-1);
                    res += recursive(8,N-1);
                    res += recursive(0,N-1);
                    return res;
                break;
                case 0:
                    res += recursive(7,N-1);
                    return res;
                break;
            }
        }
        return res;
    }


    long countPasswords(int N){
        long res = 0;
        res += recursive(7,N);
        res += recursive(7,N-1);
        res += 6 * recursive(2,N-1);
        res += 2 * recursive(2,N);
        res += 4 * recursive (4,N-1);
        res += 2 * recursive(4,N);
        return res;
    }



};

#endif