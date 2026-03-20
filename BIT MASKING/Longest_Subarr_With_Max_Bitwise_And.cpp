#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int maxi = *max_element(begin(nums),end(nums));
    int len = 0, maxLen = 1;
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] == maxi){
        len++;
        maxLen = max(maxLen,len);
      } else {
        len = 0;
      }
    }
    return maxLen;    
    }
};