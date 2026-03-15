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
    // Total digits - 10
    // Mask has 2 choices, set , unset
    // No of mask states = 2 ^ 10 = 1024
    int dp[11][2][2][1024][2];

    int solve(string &s, int i, bool tight, bool rep, int mask, int lz){
      if(i == (int)s.size()){
        return rep == 1;
      }

      if(dp[i][tight][rep][mask][lz] != -1){
        return dp[i][tight][rep][mask][lz];
      }
      
      int lb = 0;
      int ub = (tight == true) ? s[i] -'0' : 9;
      int res = 0;

      for(int d = lb; d <= ub; d++){
        if(lz && d == 0){
          res += solve(s, i + 1, (tight && (d == ub)), 0, 0, 1);
        } else {
          // Check in mask which dig are repeated 
          bool isDigUsed = 1 & (mask >> d);
          
          res += solve(s, i + 1, (tight && (d == ub)),(rep || isDigUsed ), (mask | (1 << d)), 0);
        }
      }

    return dp[i][tight][rep][mask][lz] = res;
    }

    int numDupDigitsAtMostN(int n) {
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, 1, 0, 0,1);
    }
};

//! No's Having Atleast 1 reapting dig = Total No's - All unique No's
//* This reduces 1 dimension called repetition

class Solution {
public:
    // Total digits - 10
    // Mask has 2 choices, set , unset
    // No of mask states = 2 ^ 10 = 1024
    int dp[11][2][1024][2];

    int solve(string &s, int i, bool tight, int mask, int lz){
      if(i == (int)s.size()){
        return 1;
      }

      if(dp[i][tight][mask][lz] != -1){
        return dp[i][tight][mask][lz];
      } 

      int ub = tight ? s[i] -'0' : 9;
      int res = 0;

      for(int d = 0; d <= ub; d++){
        
        int newTight = tight && (d == ub);

        if(lz && d == 0){
          res += solve(s, i + 1, newTight, mask, 1);
        } else {
          // If digit is already present in our no's skip and take next
          if(mask & (1 << d)){
            continue;
          }

          res += solve(s, i + 1, newTight, (mask | (1 << d)), 0);
        }
      }

    return dp[i][tight][mask][lz] = res;
    }

    int numDupDigitsAtMostN(int n) {
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    int unique =  solve(s, 0, 1, 0, 1);
    // remove the 0 since we want from [1,n]
    return n - (unique - 1);
    }
};