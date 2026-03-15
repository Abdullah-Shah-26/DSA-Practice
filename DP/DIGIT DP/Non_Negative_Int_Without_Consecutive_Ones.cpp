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
    // Binary Rep of 10^9 -- 30 digits 
    int dp[30][2][2];

    int f(string &s, int i, bool tight, bool prev){
      if(i == (int)s.size()){
        return 1;
      }

      if(dp[i][tight][prev] != -1){
        return dp[i][tight][prev];
      }

      int ub = tight ? s[i]-'0' : 1;

      int res = 0;
      for(int d = 0; d <= ub; d++){
        // Current dig = 1 & prevDig = 1 ---> Result in 2 consecutive ones ---> skip
         if(d == 1 && prev == 1){
          continue;
         }

         bool newTight = (tight && (d == ub));
         bool newPrev = (d == 1);
         res += f(s, i + 1, newTight, newPrev);
      }

      return dp[i][tight][prev] = res; 
    }

    int findIntegers(int n) {
    // Convert n ---> Binary Representation ----> To String
    string s = bitset<32>(n).to_string();
    // Start from 1st bit set from left
    int i =  s.find('1');
    s = s.substr(i);
    memset(dp, -1, sizeof(dp));
    return f(s, 0, 1, 0);
    }
};