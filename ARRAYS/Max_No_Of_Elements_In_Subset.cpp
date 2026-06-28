#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int maximumLength(vector<int>& nums) {
    int n = nums.size();

    unordered_map<ll,int> mp;

    for(int x : nums){
      mp[x]++;
    }

    int ans = 0;

    if(mp[1] & 1) ans = mp[1]; // [1,1,1,1,1] valid 
    else ans = mp[1] - 1; // [1,1,1,1] - invalid - decrease by 1

    for(auto &[x, _] : mp){
      if(x == 1) continue;

      ll cur = x;
      int len = 0;

      // General Pattern 
      // [x x^2 x^3 x^2 x] 
      while(mp.count(cur) && mp[cur] > 1){
        len += 2;
        cur = cur * cur;
      }

      // If x^3 exist once, make it peak
      if(mp.count(cur) == 1)
        len += 1;
      // If x^2 didnt exist, then [x] is valid,
      else
        len -= 1;

      ans = max(ans, len);
    }
    
    return ans;
  }
};