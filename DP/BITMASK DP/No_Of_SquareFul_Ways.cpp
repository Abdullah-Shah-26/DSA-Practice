#include <bits/stdc++.h>
using namespace std;

//* TC = O(N * 2^N  + N^2)
//* SC = O(N * 2^N  + N^2  + N)

class Solution {
  public:
    int n;
    // last = last chosen idx

    int dfs(int mask, int last, vector<int> &nums, vector<vector<int>> &adj, vector<vector<int>> &dp){

      if(mask == (1 << n) - 1)
        return 1; // Found 1 valid way

      if(dp[mask][last] != -1)
        return dp[mask][last];

      int ways = 0;

      for(int next : adj[last]){ // next is Idx
        
        if(mask & (1 << next)) // already in mask 
          continue;

        // Handle duplicates
        // Pick indexes in order 
        // [1a 1b 2]
        // Cannot pick [1b 1a 2] - Invalid
        if(next > 0 && nums[next] == nums[next - 1] && !(mask & (1 << (next -1))))
        continue;

        ways += dfs(mask | (1 << next), next, nums, adj, dp); 
      }

      return dp[mask][last] = ways;
    }

    int numSquarefulPerms(vector<int>& nums) {
    n = nums.size(); 
    
    // Duplicate adj checks work when array is sorted only
    sort(begin(nums), end(nums)); 

    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        
        int sq = nums[i] + nums[j];
        int r = sqrt(sq);

        // build edges if adj elements sum is perfect square
        if(r * r == sq){
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    // dp[mask][prevIdx] = no of ways 
    vector<vector<int>> dp(1 << n, vector<int> (n, -1));
    
    int ans = 0;

    for(int i = 0; i < n; i++){

      // Skip duplicates at start
      if(i > 0 && nums[i] == nums[i-1])
        continue;
      
      ans += dfs(1 << i, i, nums, adj, dp);
    }

    return ans;
    }
};