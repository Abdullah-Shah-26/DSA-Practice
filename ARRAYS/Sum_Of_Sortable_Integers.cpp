#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int sortableIntegers(vector<int>& nums) {
    int n = nums.size();
    int ans = 0; 

    for(int k = 1; k <= n; k++){
      if(n % k != 0)
        continue;

      bool validK = true;
      int prevMax = -1e9; // Max of previous block must be < min of next block

      for(int i = 0; i < n; i += k){ // Iterating over all blocks of size k
        int curMin = 1e9;
        int curMax = -1e9;
        int rem = 0; // No of break points in our monotonicity can atmax be 1 so that it can be fixed via cyclic rotation

        for(int j = 0; j < k; j++){
          curMin = min(curMin, nums[i + j]);
          curMax = max(curMax, nums[i + j]);

          if(j < k - 1 && nums[i + j] > nums[i + j + 1])
            rem++;
        }

        if(nums[i + k - 1] > nums[i])
          rem++;

        if(curMin < prevMax || rem > 1){
          validK = false;
          break;
        }

        prevMax = curMax;
      }

      if(validK)
        ans += k;
    }

    return ans;
  }
};