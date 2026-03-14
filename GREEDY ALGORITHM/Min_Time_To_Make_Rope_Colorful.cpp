#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Recursion - TC = O(2 ^ N) --- > O(N^2) - MLE 
class Solution {
public:
    int f(int i, int prev, string &colors, vector<int>& time, vector<vector<int>> &dp){
      if(i == (int)colors.size()){
        return 0;
      }

      if(dp[i][prev] != -1){
        return dp[i][prev];
      }
      // If colors are diff - No need to remove
      if(colors[i] != colors[prev]){
        return dp[i][prev] = f(i + 1, i, colors, time, dp);
      }
      // Colors are same - removeCurr/removePrev
      int removeCurr = time[i] + f(i + 1, prev, colors, time, dp);
      int removePrev = time[prev] + f(i + 1, i, colors, time, dp);

      return dp[i][prev]= min(removeCurr, removePrev);
    }

    int minCost(string colors, vector<int>& time) {
        int n = colors.size();
        vector<vector<int>>dp(n , vector<int>(n, -1));
        return f(1, 0, colors, time, dp);
    }
};

//! Greedy - O(N) Single Pass
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
    int cost = 0;
    int prevIdx = 0;
    int n = colors.size();

    for(int i = 1; i < n; i++){
      if(colors[prevIdx] == colors[i]){
        if(time[prevIdx] > time[i]){
          cost += time[i];
        }else{ // time[i] > time[prevIdx]
          cost += time[prevIdx];
          prevIdx = i;
        }
      }else{ // No need to remove, prevIdx gets updated
        prevIdx = i;
      }
    }
    return cost;   
    }
};