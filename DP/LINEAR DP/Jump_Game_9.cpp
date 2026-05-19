#include <bits/stdc++.h>
using namespace std;

// TC = SC = O(N)

class Solution {
  public:
    vector<int> maxValue(vector<int>& nums) {
    int n = nums.size();

    vector<int> maxLeft(n, 0); // maxLeft[i] = max element from idx 0 till i
    vector<int> minRight(n, 0); // minRight[i] = min element from idx i + 1 till n

    maxLeft[0] = nums[0];
    minRight[n-1] = nums[n-1];

    // for(int i = 1; i < n; i++){
    //   maxLeft[i] = max(maxLeft[i-1], nums[i]);
    // }

    // for(int i = n-2; i >= 0; i--){
    //   minRight[i] = min(minRight[i+1], nums[i]);
    // }

    for(int i = 1; i < n; i++){
      maxLeft[i] = max(maxLeft[i-1], nums[i]);
      minRight[n-i-1] = min(minRight[n-i], nums[n-i-1]); 
    }

    vector<int> ans(n, 0);
    ans[n-1] = maxLeft[n-1];

    for(int i = n-2; i >= 0; i--){
      if(maxLeft[i] <= minRight[i+1]){ // Can't go to right at all
        ans[i] = maxLeft[i];
      }
      else{
        ans[i] = ans[i+1];
      }
    }

    return ans;
    }
};