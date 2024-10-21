#ifndef BLOCKENEMY_HPP
#define BLOCKENEMY_HPP

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <map>


class BlockEnemy {
public:
    std::vector<std::set<int>> adjList; 
    std::map<int, std::map<int, int>> costMap;

    bool isOccupied(int node, const std::vector<int>& occ_towns) {
        return std::find(occ_towns.begin(), occ_towns.end(), node) != occ_towns.end();
    }

    // Recursive function for DFS
    bool dfsHelper(int node, std::vector<bool>& visited, std::vector<int>& town_path, std::vector<int>& occ_towns) {
        if (node < 0 || node >= visited.size()) {
            // std::cerr << "Error: Node " << node << " is out of bounds!" << std::endl;
            return false;
        }

        visited[node] = true;  // Mark current node as visited
        town_path.push_back(node);

        // Debugging statement to trace DFS
        // std::cout << "DFS visiting node: " << node << std::endl;

        for (int neighbor : adjList[node]) {
            // Check if the neighbor is a valid node
            if (neighbor < 0 || neighbor >= adjList.size()) {
                // std::cerr << "Invalid neighbor: " << neighbor << std::endl;
                continue;
            }

            if (!visited[neighbor]) {
                if (isOccupied(neighbor, occ_towns)) {
                    // We reached another occupied town, stop the DFS here
                    town_path.push_back(neighbor);
                    // std::cout << "Found occupied town: " << neighbor << std::endl;
                    return true;
                } else {
                    if (dfsHelper(neighbor, visited, town_path, occ_towns)) {
                        return true;
                    }
                }
            }
        }

        // Debugging statement to show backtracking
        // std::cout << "Backtracking from node: " << node << std::endl;

        // If we return here, it means no occupied town was found along this path
        town_path.pop_back();  // Backtrack
        return false;
    }


    // Main function
    int minEffort(int N, std::vector<std::string> roads, std::vector<int> occupiedTowns) {
        // Clear the adjList and costMap to avoid sharing state between test cases
        adjList.clear();
        costMap.clear();
        
        // Edge case 1: Only one occupied town
        if (occupiedTowns.size() == 1) {
            return 0;
        }

        adjList.resize(N);
        int max_cost = 0;

        for (const auto& road : roads) {
            std::stringstream ss(road);
            int u, v, w;
            ss >> u >> v >> w;

            adjList[u].insert(v);
            adjList[v].insert(u);
            costMap[u][v] = w;
            costMap[v][u] = w;
            max_cost += w;
        }

        // Edge case 2: All towns are occupied
        if (occupiedTowns.size() == N) {
            return max_cost;
        }

        int totalEffort = 0;
        std::set<std::pair<int, int>> destroyedRoads;

        for (auto occ_town : occupiedTowns) {
            bool checking = true;

            while (checking) {
                std::vector<bool> visited(N, false);
                std::vector<int> town_path;

                // Perform DFS from the current occupied town
                if (!dfsHelper(occ_town, visited, town_path, occupiedTowns)) {
                    // If no other occupied town is found, stop checking
                    checking = false;
                    break;
                }

                // Debugging statement for town path
                /*
                std::cout << "Town path found: ";
                for (int node : town_path) {
                    std::cout << node << " ";
                }
                std::cout << std::endl;
                */

                // We have a path between two occupied towns, remove the cheapest road
                int minCost = INT_MAX;
                int source_delete = -1, dest_delete = -1;

                for (int i = 0; i < town_path.size() - 1; ++i) {
                    int u = town_path[i];
                    int v = town_path[i + 1];
                    
                    // Check if road is already destroyed
                    if (destroyedRoads.find({u, v}) != destroyedRoads.end()) {
                        continue;
                    }

                    if (costMap[u][v] < minCost) {
                        minCost = costMap[u][v];
                        source_delete = u;
                        dest_delete = v;
                    }
                }

                // Debugging statement for road removal
                /*
                if (source_delete != -1 && dest_delete != -1) {
                    std::cout << "Destroying road between " << source_delete << " and " << dest_delete 
                              << " with cost " << minCost << std::endl;
                } else {
                    std::cout << "No valid road to delete" << std::endl;
                }

                if (source_delete == -1 || dest_delete == -1) {
                    checking = false;  // No valid road to delete
                    break;
                }
                */

                totalEffort += minCost;

                // Mark the road as destroyed
                destroyedRoads.insert({source_delete, dest_delete});
                destroyedRoads.insert({dest_delete, source_delete});

                // Remove the road from the adjacency list
                adjList[source_delete].erase(dest_delete);
                adjList[dest_delete].erase(source_delete);
            }
        }

        return totalEffort;
    }
};

#endif
