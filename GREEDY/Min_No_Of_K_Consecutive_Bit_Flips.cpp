#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)

class Solution {
public:
  int minKBitFlips(vector<int>& nums, int k) {
  int n = nums.size();
  int ans = 0, times = 0;
  
  vector<bool> flip(n, 0);

  for(int i = 0; i < n; i++){
    if(i >= k)
      times -= flip[i - k];

    if((nums[i] == 1 && (times & 1)) || (nums[i] == 0 && (times % 2 == 0))){
      if(i + k > n)
        return -1;

      ans++;
      times++;
      flip[i] = 1;
    }
  }    

  return ans;
  }
};