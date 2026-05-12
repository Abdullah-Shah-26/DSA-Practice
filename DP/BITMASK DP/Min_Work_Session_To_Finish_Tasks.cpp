#include <bits/stdc++.h>
using namespace std;

// TC = O(2^n * n)
// SC = O(2^n)

class Solution {
  public:
    int minSessions(vector<int>& tasks, int sessionTime) {
    int n = tasks.size();

    // dp[mask] = {min sessions so far, time used in current task}
    vector<pair<int,int>> dp(1 << n, {1e9,1e9});   
    dp[0] = {1,0}; // We currently have 1 empty active session

    for(int mask = 0; mask < (1<<n); mask++){
      auto [sess, used] = dp[mask];

      for(int i = 0; i < n; i++){
        if(mask & (1<<i)) continue; // skip tasks, that are already done
        int newMask = mask | (1<<i); 

        // Can we do ith task in this session
        if(used + tasks[i] <= sessionTime)
          dp[newMask] = min(dp[newMask], {sess, used + tasks[i]});
        else
          dp[newMask] = min(dp[newMask], {sess + 1, tasks[i]});        
      }
    }
    return dp[(1<<n)-1].first; // min sessions we need
    }
};