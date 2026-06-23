#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums) {
  int n = nums.size();
  int times = 0; // No of times it got flipped
      
  for(int i = 0; i < n; i++){
    if((nums[i] == 1 && (times & 1)) || (nums[i] == 0 && (times % 2 == 0))){
      times++;
    }
  }

  return times;
  }
};