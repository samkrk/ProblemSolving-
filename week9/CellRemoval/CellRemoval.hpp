#ifndef CELLREMOVAL_HPP
#define CELLREMOVAL_HPP

#include <iostream>

class CellRemoval{
    public:

    int cellsLeft(std::vector<int>& parent, int deletedCell) {
        // Step 1: Build the tree using an adjacency list
        int n = parent.size();
        std::vector<std::vector<int>> tree(n);
        int root = -1;

        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = i;  // Zygote (root) of the tree
            } else {
                tree[parent[i]].push_back(i);  // Add i as a child of parent[i]
            }
        }

        // Step 2: Recursively delete the given cell and its descendants
        if (deletedCell == root) {
            return 0;  // If the root is deleted, nothing remains
        }

        deleteSubtree(tree, deletedCell);

        // Step 3: Count the remaining leaf nodes
        return countLeafNodes(tree, root) - 1;
    }

    void deleteSubtree(std::vector<std::vector<int>>& tree, int deletedCell) {
        for (int child : tree[deletedCell]) {
            deleteSubtree(tree, child);  // Recursively delete children
        }
        tree[deletedCell].clear();  // Mark the node as deleted (no children)
    }

    int countLeafNodes(const std::vector<std::vector<int>>& tree, int node) {
        // Base case: If the node has no children, it is a leaf
        if (tree[node].empty()) {
            return 1;
        }

        // Recursively count leaf nodes in the subtree
        int leafCount = 0;
        for (int child : tree[node]) {
            leafCount += countLeafNodes(tree, child);
        }
                
        return leafCount;
    }
};

#endif