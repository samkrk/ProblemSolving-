#ifndef ROCKSTAR_HPP
#define ROCKSTAR_HPP

#include <iostream>
#include <vector>

class RockStar{
    public:

    int getNumSongs(int ff, int fs, int sf, int ss){
        if (ff != 0 && fs == 0){
            return ff;
        }

        if (ff == 0 && fs == 0){
            if (sf != 0){
                return ss +1;
            }
            else {
                return ss;
            }
        }
        
        if (ff == 1 && fs == 1 && sf == 1 && ss == 1){
            return 4;
        }
        // non zero fs 
        int res = ff;
        // go ff -> fs 
        fs--;
        res ++;
        // go fs -> ss
        if (ss == 0){
            // find smallest of fs and sf 
            if (fs < sf){
                res += fs*2 + 1;
                return res;
            }
            else {
                res += 2*sf;
                return res;
            }
        }
        else {
            res += ss;
            // go ss -> sf 
            sf--;
            res++;
            if (sf == 0){
                return res+1;
            }
            // find smallest of fs and sf 
            if (sf < fs){
                res += sf*2 + 1;
                return res;
            }
            else {
                res += fs*2;
                return res;
            }
            
        }
    }

};

#endif