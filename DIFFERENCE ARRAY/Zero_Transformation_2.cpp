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
   int n;
   int Q;

   // Differance Array Technique 
   bool check(vector<int>& nums, vector<vector<int>> &queries, int k){
    vector<int> diff(n, 0);

    for(int i = 0; i <= k; i++){
      int l = queries[i][0];
      int r = queries[i][1];
      int x = queries[i][2];

      diff[l] += x;
      if(r + 1 < n)
        diff[r + 1] -= x;
    }

    // Cumulative Sum
    int cumSum = 0;
    for(int i = 0; i < n; i++){
      cumSum += diff[i];

      diff[i] = cumSum;

      if(nums[i] - diff[i] > 0){ // Unable to reduce nums[i] to 0
        return false;
      }
    }
    return true;
   }

   int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
     n = nums.size();
     Q = queries.size();

    int zerosCnt = count(nums.begin(),nums.end(), 0);
    // Already 0
    if(zerosCnt == n){
      return 0;
    }    
    // TC = O((N + Q) * Log Q)
    // SC = O(N)
    int l = 0, h = Q-1; 
    int ans = -1;
    while(l <= h){
      int mid = (l + h) >> 1;
      if(check(nums, queries, mid)){
        ans = mid + 1;
        h = mid - 1;
      }else{
        l = mid + 1;
      }
    }
    return ans;
    }
};