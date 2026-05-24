#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
  int n = nums.size();

  sort(begin(nums), end(nums));

  int best = nums[0] + nums[1] + nums[2];

  for(int i = 0; i < n; i++){
    int j = i + 1;
    int k = n - 1;

    while(j < k){
      int sum = nums[i] + nums[j] + nums[k]; 

      if(abs(sum - target) < abs(best - target)){
        best = sum;
      }
      else if(sum < target){
        j++;
      }
      else if(sum > target){
        k--;
      }
      else {
        // sum == target
        // abs(sum - target) == 0
        return target;
      }
    }
  }

  return best;   
  }
};