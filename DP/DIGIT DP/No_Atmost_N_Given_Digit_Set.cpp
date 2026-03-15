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
    int mask;
    int dp[10][2][2];
    int f(string &s, int i, bool tight, bool lz){
      if(i == (int)s.size()){
        return 1;
      }

      if(dp[i][tight][lz] != -1){
        return dp[i][tight][lz];
      }

      int lb = 0;
      int ub = (tight) ? s[i]-'0' : 9;

      int res = 0;
      for(int d = lb; d <= ub; d++){
        bool newTight = (tight) && (d == ub);

        if(lz && (d==0)){
          res += f(s, i + 1, newTight, 1);
        }else {
          // skip the digits that are not in digits array
          if((mask & (1 << d)) == 0){
            continue;
          }

          res += f(s, i + 1, newTight, 0);
        }
      }
      return dp[i][tight][lz] = res;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
    mask = 0;

    for(auto &ch : digits){
      mask |= (1 << stoi(ch));
    }    
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    // Subtract 0 since dig array can only have 1-9
    return f(s,0,1,1) - 1;
    }
};