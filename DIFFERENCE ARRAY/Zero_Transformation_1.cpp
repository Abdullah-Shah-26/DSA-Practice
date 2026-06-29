#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
  // TC = O(N + Q)
  // SC = O(N) 
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries){
    int n = nums.size();
    vector<int> diff(n + 1,0);

    for(auto &q : queries){
      int l = q[0];
      int r = q[1];

      diff[l] += 1;
      diff[r+1] -= 1;
    }
    // Coverage
    int coverage = 0;
    for(int i = 0; i < n; i++){
        coverage += diff[i];

        if(coverage < nums[i]){
          return false;
        }
    }

    return true;
    }
};