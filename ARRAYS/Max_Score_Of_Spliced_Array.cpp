#include <bits/stdc++.h>
using namespace std;

// Kadan's Algorithm : TC = O(N) | SC = O(1)

class Solution {
public:
  int solve(vector<int> nums1, vector<int> nums2){
    int sum = accumulate(begin(nums1), end(nums1), 0);
    int cur = 0, best = 0;

    for(int i = 0; i < nums1.size(); i++){
      // No swap, Start new swap at i, Extend prev swap
      cur = max({0, nums2[i] - nums1[i],cur + nums2[i] - nums1[i]});
      best = max(best, cur);
    }

    return sum + best;
  }

  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    return max(solve(nums1, nums2), solve(nums2, nums1));    
  }
};