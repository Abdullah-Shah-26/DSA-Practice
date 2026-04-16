#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Binary Search + DP
//! Greedy Fails when we have interval scheduling with weight/profit cause a latter choice may give more profit

class Solution {
public:
    int jobScheduling(vector<int>& start,
                      vector<int>& end,
                      vector<int>& profit) {

        int n = start.size();
        vector<vector<int>> job(n);
        for(int i = 0; i < n; i++)
            job[i] = {start[i], end[i], profit[i]};

        sort(job.begin(), job.end());
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
          int skip = dp[i + 1];
          int next = lower_bound(job.begin(), job.end(),
                               vector<int>{job[i][1],0,0}) - job.begin();
          int take = job[i][2] + dp[next];

          dp[i] = max(take,skip);
        }

        return dp[0];
    }
};