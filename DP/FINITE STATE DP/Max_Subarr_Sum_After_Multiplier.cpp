#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

class Solution {
public:  
  long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    vector<vector<ll>> dp(n, vector<ll> (3, -INF));

    // dp[i][0] = max subarr sum upto idx i, no ops started
    // dp[i][1] = max subarr sum upto idx i, using mul/div operation [inside operated segement]
    // dp[i][2] = max subarr sum upto idx i, operations have finished & we are back to normal nos

    // Multiply 
    dp[0][0] = nums[0];
    dp[0][1] = 1LL * nums[0] * k;
    
    for(int i = 1; i < n; i++){
      dp[i][0] = max(0LL, dp[i-1][0]) + nums[i];

      // Extend normal seg & start operation or 
      // Keep extending operated segment
      dp[i][1] = max({0LL, dp[i-1][0], dp[i-1][1]}) + 1LL * nums[i] * k;

      // [operation ended just before i, operation ended even earlier] + keep adding nos normally
      dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + nums[i];
    }

    ll ans = -INF;
    for(auto &d : dp)
      ans = max({ans, d[0],d[1],d[2]});

    dp.assign(n, vector<ll> (3, -INF));

    // Division
    dp[0][0] = nums[0];
    dp[0][1] = nums[0]/k;
    for(int i = 1; i < n; i++){
      dp[i][0] = max(0LL, dp[i-1][0]) + nums[i];
      dp[i][1] = max({0LL, dp[i-1][0], dp[i-1][1]}) + nums[i]/k;
      dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + nums[i];
    }  

    for(auto &d : dp)
      ans = max({ans, d[0], d[1], d[2]});

    return ans;
  }
};