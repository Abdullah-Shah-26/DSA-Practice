#include <bits/stdc++.h>
using namespace std;

// Like LIS Reconstruction 

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();

    // Sorting so every multiple appear after divisor
    // Correct Order Ex : 1 2 3 4 6 12 
    sort(begin(nums), end(nums));

    vector<int> parent(n, 0);
    iota(begin(parent), end(parent), 0);

    // dp[i] = len of largest divisible subset ending at idx i
    vector<int> dp(n, 1);
  
    for(int i = 0; i < n; i++){
      for(int j = 0; j < i; j++){
        if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
          dp[i] = 1 + dp[j];
          parent[i] = j;
        }
      }
    }

    vector<int> ans;

    int maxIdx = max_element(begin(dp), end(dp)) - begin(dp);
    int cur = maxIdx;

    while(cur != parent[cur]){
      ans.push_back(nums[cur]);
      cur = parent[cur];
    }
    
    ans.push_back(nums[cur]);
    reverse(begin(ans), end(ans));

    return ans;
  }
};