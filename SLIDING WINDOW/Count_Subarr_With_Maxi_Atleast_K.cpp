#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = std::vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

class Solution {
public:
    //! TC = O(N)
    //! SC = O(1)
    long long countSubarrays(std::vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());
    long long ans = 0;
    int maxi = *std::max_element(std::begin(nums), std::end(nums));
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
  