#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)

class Solution {
public:
  int minKBitFlips(vector<int>& nums, int k) {
  int n = nums.size();
  int ans = 0, times = 0;
  vector<bool> flip(n, false);

  for(int i = 0; i < n; i++){
    if(i >= k) // Removing effect of flip that doesnt apply to current window [i-k+1, i]
      times -= flip[i - k];

    if((nums[i] == 1 && (times & 1)) || (nums[i] == 0 && (times % 2 == 0))){
      if(i + k > n) // Cannot fix last (k - 1) bits even if they need, since we can dont have k bits to flip
        return -1;

      times++;
      ans++;
      flip[i] = 1;
    }
  }    

  return ans;
  }
};