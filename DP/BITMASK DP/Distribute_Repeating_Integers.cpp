#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canDistribute(vector<int>& nums, vector<int>& quantity) {  
    int n = nums.size();
    int m = quantity.size();

    unordered_map<int, int> mp;

    for(int x : nums)
      mp[x]++;

    vector<int> freq;

    for(auto &[value, cnt] : mp)
      freq.push_back(cnt);

    // sum[mask] = Total quantity needed by customers in mask
    vector<int> sum(1 << m, 0);

    for(int mask = 1; mask < (1 << m); mask++){
      for(int j = 0; j < m; j++){
        if(mask & (1 << j)){
          sum[mask] += quantity[j];
        }
      }
    }
    
    vector<bool> dp(1 << m, false); // dp[mask] = can we satisfy these customers ? 

    dp[0] = true; // Nobody satisfied 

    for(auto &f : freq){
      vector<bool> ndp = dp;

      for(int mask = 0; mask < (1 << m); mask++){

        if(!dp[mask])
          continue;

        // Try every group of remaining customers 
        for(int sub = 0; sub < (1 << m); sub++){
          
          // Sub must contain un-satisfied customers
          if(mask & sub)
            continue;

          // Demand > Freq
          if(sum[sub] > f)
            continue;

          int newMask = mask | sub;

          ndp[newMask] = true;
        }
      }
      
      dp = ndp;
    }

    return dp[(1 << m) - 1];
  }
};