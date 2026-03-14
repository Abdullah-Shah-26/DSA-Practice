#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Co-ordinate DP - Single Pass - TC = O(N + Rides) - SC = O(N)
//! Can also be solved using KnapSack DP + Binary Search - O(NLogN) SC = O(N)

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<vector<pair<int, long long>>>endAt(n + 1);

    for(auto &r : rides){
      int st = r[0];
      int end = r[1];
      long long profit = end - st + r[2];

      endAt[end].push_back({st,profit});
    }    

    vector<long long>dp(n + 1, 0);

    for(int i = 1; i <= n; i++){
      
      dp[i] = dp[i-1]; // Skip 

      for(auto &it : endAt[i]){
        int st = it.first;
        long long profit = it.second;

        dp[i] = max(dp[i], dp[st] + profit);
      }

    }
    return dp[n];
    }
};