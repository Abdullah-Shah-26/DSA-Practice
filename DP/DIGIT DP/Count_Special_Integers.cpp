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
    // No of digits being represented using mask - [0-9] = 10
    // Total mask states = 2^10 = 1024
    int dp[11][2][1024][2];
    int f(string &s, int i, bool tight, int mask, bool lz){
      if(i == (int)s.size()){
        return 1;
      }

      if(dp[i][tight][mask][lz] != -1){
        return dp[i][tight][mask][lz];
      }

      int lb = 0;
      int ub = (tight) ? s[i] - '0' : 9;

      int res = 0;
      for(int d = lb; d <= ub; d++){
        bool newTight = (tight) && (d == ub);

       
        // Leading zeros
        if(lz && d == 0){
          res += f(s, i + 1, newTight, mask, 1);
        } else {
        // Skip used digits
          if(mask & (1 << d)){
            continue;
          }

          int newMask = (mask | (1 << d));
          res += f(s, i + 1, newTight, newMask, 0);
        }
      }

      return dp[i][tight][mask][lz] = res;
    }

    int countSpecialNumbers(int n) {
    string s = to_string(n);
    // -1 for removing 0 since the interval is [1,n]
    memset(dp, -1, sizeof(dp));
    return f(s,0,1,0,1) - 1;    
    }
};