#include <bits/stdc++.h>
using namespace std;

//! TSP - BottomUp
//* TC = O(N^2 * 2^N)
//* SC = O(N * 2^N)

class Solution {
    public:
    const int INF = 1e9;
    
    int tsp(vector<vector<int>>& cost) {
    int n = cost.size();
    
    if(n == 1) // Tour is 0-->0
        return 0;
    
    // dp[mask][u] = minCost to visit nodes in mask and end at u
    vector<vector<int>> dp(1 << n, vector<int> (n, INF));
    
    // Base Case : St at node 0 & only node 0 is visited
    dp[1 << 0][0] = 0; 
    
    for(int mask = 0; mask < (1 << n); mask++){
        for(int u = 0; u < n; u++){
            
            // u must be in current mask
            if(!(mask & (1 << u))) 
                continue;
                
            // u is unreachable
            if(dp[mask][u] == INF) 
                continue;
                
            // try to go to unvisited node
            for(int v = 0; v < n; v++){
                
                if(mask & (1 << v)) // already in curMask
                    continue; 
                    
                int nextMask = mask | (1 << v);
                
                dp[nextMask][v] = min(dp[nextMask][v], cost[u][v] + dp[mask][u]);
            }
        }
    }
    
    // Complete tour - return to st
    int fullMask = (1 << n) - 1;
    int ans = INF;
    
    for(int u = 1; u < n; u++){
        ans = min(ans, dp[fullMask][u] + cost[u][0]);
    }
    
    return ans;
    }
};