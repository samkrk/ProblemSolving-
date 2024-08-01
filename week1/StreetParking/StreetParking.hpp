#ifndef STREETPARKING_HPP
#define STREETPARKING_HPP

#include <iostream>
#include <vector> 

class StreetParking{
public: 
    int freeParks(std::string street){
        std::vector<int> parks(street.size(),0);

        for (int i = 0 ; i < street.size() ; i++){
            // driveways 
            if (street[i] == 'D'){
                parks.at(i) = 1;
            }
            // bus stops 
            else if (street[i] == 'B'){
                // check that i > 2 
                if (i < 2){
                    if (i == 0){
                        parks.at(i) = 1;
                    }
                    else if (i==1){
                        parks.at(i) = 1;
                        parks.at(i-1) = 1;
                    }
                }
                else {
                    parks.at(i) = 1;
                    parks.at(i-1) = 1;
                    parks.at(i-2) = 1;
                }
            }
            // side streets 
            else if (street[i] == 'S'){
                // check that i > 1 and i < street.size()
                if (i < 1){
                    parks.at(i) = 1;
                    if (street.size() > 1){
                        parks.at(i+1) = 1;
                    }
                }
                else if (street.size()-i == 1){ // if 'S' is last element in string 
                    parks.at(i) = 1;
                    parks.at(i-1) = 1;
                }  
                else {
                    parks.at(i-1) = 1;
                    parks.at(i) = 1;
                    parks.at(i+1) = 1;
                }
            }
        }

        int available = 0; 
        for (int i = 0 ; i < parks.size() ; i++){
            if (parks.at(i) == 0){
                available++;
            }
        }

        return available;
    }

};


#endif 