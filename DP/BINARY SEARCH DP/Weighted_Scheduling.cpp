#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DP + Binary Search 
//* NLogN
class Solution {
  public:
    vector<int>dp;
  
    int maxProfit(vector<vector<int>> &jobs) {
    sort(begin(jobs), end(jobs));
    int n = jobs.size();
    dp.assign(n+1, 0);
    
    for(int i = n-1; i >= 0; i--){
        int skip = dp[i + 1];
        
        int next = lower_bound(jobs.begin(),jobs.end(), vector<int>{jobs[i][1], 0, 0}) - jobs.begin();
        int take = jobs[i][2] + dp[next];
        
        dp[i]= max(take, skip);
    }
    
    return dp[0];
    }
};