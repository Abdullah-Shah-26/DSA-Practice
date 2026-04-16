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
   // KnapSack Dp 
   // Can use MITM too but inefficient
    int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    //! TC = O(N*sum)
    //! SC = O(sum)
    int sum = accumulate(stones.begin(), stones.end(), 0);
    vector<int> dp(sum/2 + 1, 0);

    for(int i = n-1; i >= 0; i--){
      for(int t = sum/2; t >= stones[i] ; t--){
          dp[t] = max(stones[i] + dp[t - stones[i]], dp[t]);
      }
    }
    return sum - 2*dp[sum/2];
    }
};