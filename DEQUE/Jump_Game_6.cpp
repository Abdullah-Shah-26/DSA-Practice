#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }


//! TC = O(N)
//! SC = O(N)


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    deque<int> dq;
    dq.push_back(0);

    for(int i = 1; i < n; i++){
      // Remove out of window elements
      while(!dq.empty() && dq.front() < i - k) dq.pop_front();

      dp[i] = nums[i] + dp[dq.front()];

      // Maintain Monotonic decreasing order
      while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();

      dq.push_back(i);
    }   

    return dp[n-1];
    }
};

//! TC = O(N)
//! SC = O(K)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    // dp value, idx
    deque<pair<int,int>> dq;
    dq.push_back({nums[0], 0}); 
    int cur = nums[0];
    for(int i = 1; i  < n; i++){
      // Remove out of bound elements
      while(!dq.empty() && dq.front().second < i - k) dq.pop_front();

      cur = nums[i] + dq.front().first;

      // Maintain Monotonic Decreasing Order
      while(!dq.empty() && dq.back().first <= cur) dq.pop_back();

      dq.push_back({cur, i});
    }
    return cur;
    }
};