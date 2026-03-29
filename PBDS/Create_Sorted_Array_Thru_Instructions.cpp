#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

const int MOD = 1e9 + 7;

//! TC = O(N Log N)
//! SC = O(N)

class Solution {
  public:
    int createSortedArray(vector<int>& nums) {
    
    oset os;  
    int n = nums.size();
    long long cost = 0;

    for(int i = 0; i < n; i++){
      int value = nums[i];

      // Strictly smaller than value to be inserted
      int x = os.order_of_key(value);

      int m = os.size();

      // Strictly greater than value to be inserted
      int y = m - os.order_of_key(value + 1); // Total - (<= value)

      cost = (cost + min(x,y))%MOD;

      os.insert(value);
    }

    return cost;
    }
};