#include <bits/stdc++.h>
using namespace std;

//! Greedy + 2 pointer center expansion - Choose side with larger neighbour
//* TC = O(N) | SC = O(1)

class Solution {
  public:
    int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int l = k, r = k;
    
    int ans = nums[k];
    int mini = nums[k];

    while(l > 0 || r < n-1){
     
      if(l == 0) r++; // Can't go further left, go right
      else if(r == n-1) l--; // vice versa

      else if(nums[l-1] > nums[r + 1]) l--; // Expands towards larger min
      else r++;

      mini = min({mini, nums[l], nums[r]});

      ans = max(ans, (r-l+1)*mini);
    }   

    return ans;  
    }
};  