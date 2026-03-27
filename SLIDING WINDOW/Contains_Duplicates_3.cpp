#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Sliding Winodow + MultiSet

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int valueDiff) {
    int n = nums.size();
    // TC = O(N Log K)
    // SC = O(K)

    multiset<long long> st;

    for(int i = 0; i < n; i++){
      
      if(i > k){
       st.erase(st.find(nums[i-k-1]));
      }

      auto it = st.lower_bound(nums[i] - valueDiff);
      if(it != st.end() && *it <= nums[i] + valueDiff) return 1;

      st.insert(nums[i]);
    }
    return 0;
    }
};