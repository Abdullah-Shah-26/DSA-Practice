#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

using ll = long long;
class Solution {
public:
    // idx, tight, prevDigit, direction, maxSum, leadingZeros
    ll dp[16][2][11][4][136][2];

    /*
    Directions :  
    0 - direction not decided
    1 - inc 
    2 - dec
    3 - invalid - breaks monotone rule
    */
    
    bool goodSum[136]; 

    bool isGood(int x){
      string s = to_string(x);

      // assumption flags
      bool inc = true;
      bool dec = true;

      for(int i = 1; i < (int)s.size(); i++){
        char prevDig = s[i-1];
        char curDig = s[i];

       // Not strictly increasing 
        if(curDig <= prevDig){
          inc = false;
        }
       // Not strictly decreasing
        if(curDig >= prevDig){
          dec = false;
        }
      }
      return inc || dec;
    }

    ll f(string &s, int i, bool tight, int prev, int dir, int sum, bool lz){
      
      if(i == (int)s.size()){

          bool mono = (!lz && dir != 3);
          bool sumIsGood = goodSum[sum];

          return mono || sumIsGood;
      }

      if(dp[i][tight][prev][dir][sum][lz] != -1){
        return dp[i][tight][prev][dir][sum][lz];
      }

      ll res  = 0;
      int lb = 0;
      int ub = tight ? s[i]-'0' : 9;

      for(int d = lb; d <= ub; d++){

        bool newTight = tight && (d == ub);
        
        if(lz && d == 0){
          // Still Leading Zeros
          res += f(s, i + 1, newTight, 0, 0, sum, 1);
          continue;
        }

        if(lz){
          // First NonZero Digit
          res += f(s, i + 1, newTight, d, 0, sum + d, 0);
          continue;
        }

        int newDir = dir;

        // If direction is not determined 
        if(dir == 0){

          // Determine it
          if(d > prev){ 
            newDir = 1; // Inc 
          }
          else if(d < prev){
            newDir = 2; // Dec
          }
          else {
            newDir = 3; // Invalid
          }

        }

        else if(dir == 1 && d <= prev){
          newDir = 3;
        }
        else if(dir == 2 && d >= prev){
          newDir = 3;
        }

        res += f(s, i + 1, newTight, d, newDir, sum + d, 0);
      }
      return dp[i][tight][prev][dir][sum][lz] = res;
    }

    ll solve(ll x){
      
      if(x < 0){
        return 0;
      }

      memset(dp, -1, sizeof(dp));

      string s = to_string(x);

      return f(s, 0, 1, 0, 0, 0, 1);
    }

    ll countFancy(ll l,ll r) {
      
      for(int i = 0; i <= 135; i++){
        goodSum[i] = isGood(i);
      }

      return solve(r) - solve(l - 1);
    }
};