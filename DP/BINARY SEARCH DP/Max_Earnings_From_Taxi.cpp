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
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    //! DP + Binary Search 
    // TC = O(M log M)
    // SC = O(M)
    int m = rides.size();
    sort(begin(rides),end(rides));
    vector<long long>dp(m + 1, 0);
    for(int i = m-1; i >= 0; i--){
      long long skip = dp[i + 1];

      int next = lower_bound(rides.begin(), rides.end(),vector<int>{rides[i][1], 0,0}) - rides.begin();

      long long take = rides[i][1] - rides[i][0] + rides[i][2] + dp[next];

      dp[i] = max(take, skip);
    }    
    return dp[0];
    }
};

