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
    // TC = O(N Log N)
    // SC = O(1)

    bool isPossible(vector<int> &nums, int mid, int k){
      int house = 0;
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= mid){
          house++;
          i++;
        }
      }

      return house >= k;
    }    

    int minCapability(vector<int>& nums, int k) {
    int n  = nums.size();

    int l = *min_element(begin(nums),end(nums));
    int r = *max_element(begin(nums),end(nums));

    int result = r;

    while(l <= r){
      int mid = (l + r) >> 1;

      if(isPossible(nums, mid, k)){
        result = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } 

    return result;
    }
};