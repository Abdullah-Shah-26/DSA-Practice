#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> oset; 

//! TC = O(N Log N)
//! SC = O(N)

class Solution {
public:
    ll numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    int n = nums1.size();
    oset os;

    // nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
    
    // Rearranged Equality: 
    // nums1[i] - nums2[i] <= (nums1[j] - nums2[j] + diff)

    ll cnt = 0;

    for(int i = n-1; i >= 0; i--){
      ll value = nums1[i] - nums2[i];

      int sz = os.size();
      // Guys < value
      ll y = os.order_of_key(value);
      // Guys >= value
      ll z = sz - y;

      cnt += z;

      os.insert(value + diff); 
    }

    return cnt;
    }
};