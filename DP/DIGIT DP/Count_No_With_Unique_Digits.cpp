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
    // digits Used = 10
    // Total Mask states - 2^10 = 1024
    int dp[11][2][2][1024];
    int f(string &s, int i, bool tight, bool lz, int mask){
      if(i == (int)s.size()){
        return 1;
      }

      if(dp[i][tight][lz][mask] != -1){
        return dp[i][tight][lz][mask];
      }

      int lb = 0;
      int ub = (tight) ? s[i]-'0' : 9;

      int res = 0;
      for(int d = lb; d <= ub; d++){
      bool newTight = (tight) && (d == ub);

      // Handling Leading Zeros
        if(lz && d == 0){
          res += f(s, i + 1, newTight, 1, mask);
        } else{
        // If the dig is already used, skip & take next
        if(mask & (1 << d)){
          continue;
        }

        int newMask = (mask | (1 << d));
        res+= f(s, i + 1, newTight, 0,newMask);
        }
      }
      return dp[i][tight][lz][mask]= res;
    }

    int countNumbersWithUniqueDigits(int n) {
    int N = pow(10, n) - 1;
    string s = to_string(N);
    memset(dp, -1, sizeof(dp));
    return f(s, 0, 1, 1, 0);      
    }
};