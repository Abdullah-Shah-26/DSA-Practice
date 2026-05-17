#include <bits/stdc++.h>
using namespace std;

// Comparator that orders (deadline, profit) pairs
// in descending order of profit
bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second > b.second;
}

// DSU “find” with path compression:
// Returns the latest free slot ≤ x.
// If parent[x] == x, slot x is free.
// Otherwise, recurse on parent[x] and compress path.
int findSlot(int x, vector<int> &parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = findSlot(parent[x], parent);
}

class Solution {
public:
    // Returns {maxJobs, maxProfit}
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // 1) Pair up deadlines and profits
        //    and find the maximum deadline value
        vector<pair<int,int>> jobs;
        int maxD = 0;
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(deadline[i], profit[i]);
            maxD = max(maxD, deadline[i]);
        }
        
        // 2) Sort jobs by profit descending
        //    So we consider the highest‑profit jobs first
        sort(jobs.begin(), jobs.end(), comp);
        
        // 3) Prepare DSU parent array for time-slots 0..maxD
        //    parent[t] = t means slot t is currently free
        vector<int> parent(maxD + 1);
        for (int t = 0; t <= maxD; ++t) {
            parent[t] = t;
        }
        
        int totalJobs = 0;    // count of scheduled jobs
        int totalProfit = 0;  // sum of their profits
        
        // 4) Greedy scheduling loop
        for (auto &job : jobs) {
            int d = job.first;   // job deadline
            int p = job.second;  // job profit
            
            // Find the latest free time slot ≤ d
            int slot = findSlot(d, parent);
            
            // If slot > 0, we can schedule this job
            if (slot > 0) {
                totalJobs++;           // one more job done
                totalProfit += p;      // add its profit
                parent[slot] = slot-1; // mark this slot occupied:
                                       // next free slot is slot-1
            }
            // else: no free slot before its deadline → skip job
        }
        
        return { totalJobs, totalProfit };
    }
};