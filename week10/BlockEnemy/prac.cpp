#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <sstream>

class BlockEnemy {
public:
    // Helper class for Union-Find (Disjoint Set Union)
    class DSU {
    public:
        std::vector<int> parent, rank;
        
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 1);
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        
        // Find the root (with path compression)
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        
        // Union two sets
        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                return true;
            }
            return false;
        }
    };

    int minEffort(int N, std::vector<std::string> roads, std::vector<int> occupiedTowns) {
        if (occupiedTowns.size() == 1) return 0;  // No need to disconnect if there's only one occupied town

        std::vector<std::tuple<int, int, int>> edges;  // (cost, town1, town2)
        
        // Parse the roads and populate the edges vector
        for (const auto& road : roads) {
            int a, b, e;
            std::stringstream ss(road);
            ss >> a >> b >> e;
            edges.push_back({e, a, b});
        }
        
        // Sort edges by cost in ascending order
        std::sort(edges.begin(), edges.end());

        // Mark the occupied towns for easy lookup
        std::vector<bool> isOccupied(N, false);
        for (int town : occupiedTowns) {
            isOccupied[town] = true;
        }

        // Initialize the disjoint set (union-find) structure
        DSU dsu(N);
        int totalEffort = 0;

        // Process edges in order of increasing cost
        for (const auto& [cost, town1, town2] : edges) {
            // If both towns are occupied and connected, destroy this road
            if (isOccupied[town1] && isOccupied[town2] && dsu.find(town1) != dsu.find(town2)) {
                dsu.unite(town1, town2);  // Join the two sets of occupied towns
                totalEffort += cost;      // Add the destruction cost
            }
        }

        return totalEffort;
    }
};

int main() {
    BlockEnemy solver;
    
    // Example 1
    int N = 5;
    std::vector<std::string> roads = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
    std::vector<int> occupiedTowns = {3, 2, 4};
    std::cout << "Minimum effort: " << solver.minEffort(N, roads, occupiedTowns) << std::endl;
    
    return 0;
}
