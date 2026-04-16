#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Binary Search + DP
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());
    int n = events.size();
    vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));

    for(int i = n-1; i >= 0; i--){
      for(int K = 1; K <= k; K++){
        int skip = dp[i+1][K];

        int next = lower_bound(events.begin(),events.end(),vector<int>{events[i][1]+1,0,0}) - events.begin();
        int take = events[i][2] + dp[next][K-1];

        dp[i][K] = max(take,skip);
      }
    }
    return dp[0][k]; 
    }
};