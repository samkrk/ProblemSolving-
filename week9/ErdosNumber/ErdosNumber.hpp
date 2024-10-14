#ifndef ERDOSNUMBERS_HPP
#define ERDOSNUMBERS_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

class ErdosNumber{
    public:

    std::vector<std::string> calculateNumbers(std::vector<std::string> publications){
        // get all the authors and their connections in an adjacency list 
        std::map<std::string, std::set<std::string> > authorMap;
        for (std::string authors : publications){  
            std::istringstream iss(authors); 
            std::string author;
            std::vector<std::string> authors_in_publication;     
            
            while (iss >> author) {
                authors_in_publication.push_back(author);
            }
            
            for (std::string main_author : authors_in_publication){
                for (std::string connection : authors_in_publication){                    
                    authorMap[main_author].insert(connection);
                }
            }
        }
 
        // determine the Erdos numbers of each author 
        std::map<std::string, int> erdos_numbers = bfs(authorMap,"ERDOS");

        // convert the map back into a vector of ints 
        std::vector<std::string> res;
        for (const auto& pair : erdos_numbers){
            std::string score;
            if (pair.second == -1){
                score = pair.first;
            } else {
                score = pair.first + " " + std::to_string(pair.second);
            }
            res.push_back(score);
        }

        return res;
    }

    std::map<std::string, int> bfs (std::map<std::string, std::set<std::string> >& authorMap, 
                                    std::string main_author){
        int n = authorMap.size();                                
        std::map<std::string, int> distance;
        for (const auto& pair : authorMap){
            distance[pair.first] = -1;
        }
        std::queue<std::string> q;

        distance[main_author] = 0;
        q.push(main_author);

        while (!q.empty()){
            std::string node = q.front();
            q.pop();

            // Traverse all connections of the current node
            for (std::string connection : authorMap[node]) {
                if (distance[connection] == -1) {  // If the connection hasn't been visited yet
                    distance[connection] = distance[node] + 1;  // Set the distance to be one more than the current node
                    q.push(connection);
                }
            }
        }
        return distance;
        }

};

    
#endif