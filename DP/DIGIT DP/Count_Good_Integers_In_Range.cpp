#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  int k;
  string s;

  ll f(ll num){
    if(num < 0) return 0;

    s = to_string(num);
    int n = s.size();

    // [pos, tight, leadingZero, prev]
    ll dp[17][2][2][10] = {};

    dp[0][1][1][0] = 1; 

    for(int pos = 0; pos < n; pos++){
      for(int tight = 0; tight < 2; tight++){
        for(int lz = 0; lz < 2; lz++){
          for(int prev = 0; prev < 10; prev++){
            ll cur = dp[pos][tight][lz][prev];
            if(cur == 0) continue;

            int limit = tight ? s[pos] - '0' : 9;

            for(int d = 0; d <= limit; d++){
              int nt = tight && (d == limit);
              int nlz = lz && (d == 0);

              if(lz) dp[pos + 1][nt][nlz][d] += cur;
              else {
                if(abs(d - prev) <= k) dp[pos + 1][nt][nlz][d] += cur;
              } 
            }
          }
        }
      }
    }

    ll ans = 0;

    for(int tight = 0; tight < 2; tight++)
      for(int prev = 0; prev < 10; prev++)
        ans += dp[n][tight][0][prev];

    return ans;  
  }

  ll goodIntegers(long long l, long long r, int k_) {
    k = k_;
    return f(r) - f(l - 1);
  }
};