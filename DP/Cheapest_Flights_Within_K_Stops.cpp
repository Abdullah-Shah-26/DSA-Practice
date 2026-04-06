#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DP on Graphs
//* TC = O(E * K)  || SC = O(K*N)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        
    // dp[i][v] = min cost to reach node v using i edges
    vector<vector<int>> dp(k + 2, vector<int> (n, INT_MAX));

    dp[0][src] = 0;

    for(int i = 1; i <= k + 1; i++){
      for(auto &e : edges){
        int u = e[0], v = e[1], w = e[2];

        // U is unreachable so meaningless to extend further
        if(dp[i-1][u] == INT_MAX) continue;

        dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
      }
    }    

    // Atmost K stops ie <= K + 1 edges
    int ans = INT_MAX;
    for(int i = 0; i <= k + 1; i++){
      ans = min(ans, dp[i][dst]);
    }

    return ans == INT_MAX ? -1 : ans;
    }
};