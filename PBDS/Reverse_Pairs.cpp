#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;

//! TC = O(N Log N)
//! SC = O(N)

class Solution {
public:
    int reversePairs(vector<int>& nums) {
    int n = nums.size();
    oset os;
    ll cnt = 0;

    for(int i = n-1; i >= 0; i--){
      ll value = nums[i];

      // strictly smaller
      ll x = os.order_of_key(value);

      cnt += x;

      os.insert(value * 2);
    }

    return cnt;
    }
};