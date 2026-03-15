#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Brute Force - DP
class Solution {
public:
    int dp[11][2][10];
    int solve(string &s, int idx, bool tight, int cnt){
      if(idx == (int)s.size()){
        return cnt;
      }

      if(dp[idx][tight][cnt] != -1){
        return dp[idx][tight][cnt];
      }

      int lb = 0;
      int ub = (tight == 1) ? s[idx] - '0' : 9;

      int res = 0;
      for(int d = lb; d <= ub; d++){

        bool newTight = (tight  &&  d == ub);
        

        res += solve(s, idx + 1, newTight, cnt + (d == 1));
      }
      return dp[idx][tight][cnt] = res;
    }

    int countDigitOne(int n) {
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 1, 0);    
    }
};