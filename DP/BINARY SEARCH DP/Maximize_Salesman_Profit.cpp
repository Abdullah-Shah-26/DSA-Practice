#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Can be done with Bottom UP DP + Binary Search - TC = O(NlogN)
//! Single Pass - Co-ordinate DP - TC = O(N + M)

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    vector<vector<pair<int, int >>> endAt(n + 1);

    for(auto &it : offers){
      int s = it[0];
      int e = it[1];
      int p = it[2];
      endAt[e + 1].push_back({s, p});
    }    

    vector<int>dp(n +  1, 0);

    for(int i = 1; i <= n; i++){
      dp[i] = dp[i-1]; // walk
      // jump
      for(auto &it : endAt[i]){
        int s = it.first;
        int p = it.second;

        dp[i] = max(dp[i], dp[s] + p);
      }
    }

    return dp[n];
    }
};