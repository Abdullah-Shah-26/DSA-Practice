#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Rec + Memo

class Solution {
  public:
    int dp[50001];
    
    int solve(int i, vector<vector<int>> &job){
      
      if(i == job.size()) return 0;
      
      if(dp[i] != -1) return dp[i];

      int skip = solve(i + 1, job);

      int end = job[i][1];
      int profit = job[i][2];

      // Find next job with start >= current end
      int next = lower_bound(job.begin() + i + 1, job.end(), vector<int> {end, INT_MIN, INT_MIN}) - job.begin();

      int take = profit + solve(next, job); 

      return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& st, vector<int>& end, vector<int>& profit) {
    int n = profit.size();
    vector<vector<int>> job(n, vector<int> (3));

    for(int i = 0; i < n; i++){
      int s = st[i];
      int e = end[i];
      int p = profit[i];

      job[i] = {s, e, p};
    }

    sort(job.begin(), job.end());

    memset(dp, -1, sizeof(dp));

    return solve(0, job);
    }
};

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