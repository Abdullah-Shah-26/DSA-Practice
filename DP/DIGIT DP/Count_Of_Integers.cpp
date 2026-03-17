#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MOD = 1e9 + 7;
class Solution {
public:
    int mini, maxi;
    string subtractOne(string &s){
      int n = s.size();
      int i = n - 1;

      while(i >= 0){
        if(s[i] > '0'){
          s[i] -= 1;
          break;
        } else {
          s[i] = '9';
          i--;
        }
      }
      if(s[0] == '0' && s.size() > 1){
        return s.substr(1);
      }
      return s;
    }

    // Worst Case : 
    // 10^22 = 10000000000000000000000 - 1
    // Worst = 01111111111111111111111 = 198
    int dp[23][2][199];

    int f(string &s, int i, bool tight, int sum){
      // Pruning Step
      if(sum > maxi){
        return 0;
      }

      if(i == (int)s.size()){
        return (sum >= mini) && (sum <= maxi);
      }

      if(dp[i][tight][sum]!=-1){
        return dp[i][tight][sum];
      }

      int lb = 0;
      int ub = tight ? s[i] - '0' : 9;

      long long res = 0;
      for(int d = lb; d <= ub; d ++){
        bool newTight = (tight) && (d == ub);
        res = res + f(s, i + 1, newTight, sum + d) % MOD;
      }

      return dp[i][tight][sum] = res % MOD;
    }
    
    int count(string a, string b, int mn, int mx) {
    a = subtractOne(a);
    mini = mn;
    maxi = mx;
    
    memset(dp, -1, sizeof(dp));
    int resL = f(a,0,1,0);
    memset(dp, -1, sizeof(dp));
    int resR = f(b,0,1,0);

    
    return (resR % MOD - resL % MOD + MOD)%MOD;
    }
};