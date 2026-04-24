#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(1)

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    // First Pass : 
    // ans[i] = pref product upto (i - 1)
 
    for(int i = 1; i < n; i++)
      ans[i] = ans[i-1] * nums[i-1]; 
    
    // Second Pass :
    // Running suff product upto (i + 1)

    int suff = 1;

    for(int i = n-2; i >= 0; i--){
      suff *= nums[i+1];
      ans[i] *= suff;
    }

    return ans;
    }
};