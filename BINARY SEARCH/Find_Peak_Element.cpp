#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
  int n = nums.size();

  int l = 0, r = n-1; 

  while(l <= r){
    int mid = (l + r) >> 1;

    if(mid > 0 && nums[mid] < nums[mid - 1])
      r = mid - 1;
    else if(mid + 1 < n && nums[mid] < nums[mid + 1])
      l = mid + 1;
    else 
      return mid;
  }

  return -1;   
  }
};