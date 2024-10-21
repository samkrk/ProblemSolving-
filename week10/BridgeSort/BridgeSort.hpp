#ifndef BRIDGESORT_HPP
#define BRIDGESORT_HPP

#include <iostream>
#include <map>
#include <list>

class BridgeSort{
    public:

    std::string print_cards(char suit, std::map<char , std::vector<int> >& cards){
        std::string res;
        char card;
        for (int i = 0 ; i < 13 ; i++){
            if (cards[suit].at(i) != 0){
                switch (i)
                {
                case 8: card = 'T'; break; 
                case 9: card = 'J'; break; 
                case 10: card = 'Q'; break; 
                case 11: card = 'K'; break; 
                case 12: card = 'A'; break; 
                default:
                    card = '2' + i;
                    break;
                }
                res.push_back(suit);
                res.push_back(card);
            }
        }
        return res;
    }

    std::string sortedHand(std::string hand){
        // initialise map 
        std::map<char , std::vector<int> > suits;
        std::vector<int> empty(13,0);
        suits['C'] = empty;
        suits['D'] = empty;
        suits['H'] = empty;
        suits['S'] = empty;
        
        // organise cards 
        int index;
        for (int i = 0 ; i < hand.size() ; i += 2){
            switch (hand[i+1])
            {
            case 'T': index = 8; break;
            case 'J': index = 9; break;
            case 'Q': index = 10; break;
            case 'K': index = 11; break;
            case 'A': index = 12; break;
            default:
                index = (hand[i+1]) - '2';
                break;
            }

            suits[hand[i]].at(index) = 1;
        }
        
        // print cards 
        std::string res = print_cards('C', suits);
        res.append(print_cards('D', suits));
        res.append(print_cards('H', suits));
        res.append(print_cards('S', suits));

        return res;
    }

};

#endif