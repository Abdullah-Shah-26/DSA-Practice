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
    //! TC = O(N)
    //! SC = O(1)
    long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    long long ans = 0;
    int maxi = *max_element(begin(nums), end(nums));
    int cntMaxi = 0;
    
    int l = 0;
    for(int r = 0; r < n; r++){
     if(nums[r] == maxi) cntMaxi++;

     while(l <= r && cntMaxi >= k){
      ans += (n - r);
      if(nums[l] == maxi) cntMaxi--;
      l++;
     }
    }   
    return ans;
    }
};