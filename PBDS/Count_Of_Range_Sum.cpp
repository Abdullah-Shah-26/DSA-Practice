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
    int countRangeSum(vector<int>& nums, int L, int R) {
    int n = nums.size();
    oset os;
    os.insert(0);

    ll cnt = 0;
    ll prefSum = 0;
    
    for(int j = 0; j < n; j++){
      prefSum += nums[j];

      ll x = os.order_of_key(prefSum - L + 1);
      ll y = os.order_of_key(prefSum - R);

      cnt += (x - y);

      os.insert(prefSum); // sum(idx - 0.....j)
    }

    return cnt;
    }
};