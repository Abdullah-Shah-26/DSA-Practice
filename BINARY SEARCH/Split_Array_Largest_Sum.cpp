#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(int x, vector<int> &nums, int k){
    int subarr = 1;
    int sum = 0;

    for(int i = 0; i < nums.size(); i++){
      if(sum + nums[i] > x){
        sum = nums[i];
        subarr++;
        continue;
      }
      sum += nums[i];
    }

    return subarr <= k;
  }

  int splitArray(vector<int>& nums, int k) {
  int l = *max_element(begin(nums), end(nums));
  int r = accumulate(begin(nums), end(nums), 0);

  int ans = r;

  while(l <= r){
    int mid = l + (r - l)/2;

    if(check(mid, nums, k)){
      ans = mid;
      r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }   

  return ans;
  }
};