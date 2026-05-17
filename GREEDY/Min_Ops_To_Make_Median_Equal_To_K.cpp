#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN)
// SC = O(1) 

// Greedy : Perform min necessary adjustments on min necessary elements

class Solution {
  public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
    int n = nums.size();
    int m = n/2;
    long long ops = 0;

    sort(nums.begin(), nums.end());

    if(nums[m] == k) return 0;

    if(nums[m] > k){
      for(int i = 0; i <= m; i++){
        if(nums[i] > k){
          ops += (nums[i] - k);
        }
      }
    }
    else{
      for(int i = m; i < n; i++){
        if(nums[i] < k){
          ops += (k - nums[i]);
        }
      }
    }

    return ops;
    }
};