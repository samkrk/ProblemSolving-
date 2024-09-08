#ifndef FAIRWORKLOAD_HPP
#define FAIRWORKLOAD_HPP

#include <vector>
#include <algorithm>
#include <numeric>

class FairWorkload {
public:
    int getMostWork(std::vector<int> folders, int workers) {
        int low = *max_element(folders.begin(), folders.end()); // minimum possible max load
        int high = accumulate(folders.begin(), folders.end(), 0); // maximum possible max load
        
        // binary search to find the smallest possible maximum load
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canPartition(folders, workers, mid)) {
                high = mid; // try to go smaller. loop will break if we find answer 
            } else {
                low = mid + 1; // failed so increase the maximum load
            }
        }
        return low;
    }

    // determine if we can partition folders into the desired number of workers
    bool canPartition(const std::vector<int>& folders, int workers, int maxLoad) {
        int currentLoad = 0;
        int requiredWorkers = 1; // Start with one worker

        for (int folder : folders) {
            if (currentLoad + folder > maxLoad) { // if we need a new worker
                requiredWorkers++;
                currentLoad = folder; // start a new workload with the current folder
                if (requiredWorkers > workers) { // if we dont have enough workers
                    return false; 
                }
            } else {                
                currentLoad += folder;
            }
        }
        return true; // success 
    }
};

#endif