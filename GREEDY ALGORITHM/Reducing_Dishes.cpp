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
    int maxSatisfaction(vector<int>& s) {
    sort(s.begin(),s.end());
    int n = s.size();
    int prefSum = 0;
    int ans = 0;
    /*
    Observation : 
    When we add something to front
    [x,a,b,c]
    oldSum = 1*a + 2*b + 3*c
           = (a + b + c) + (b + c) + c
     
     We can do reverse prefix Sum
     And add it in ans each time if it increases our curSum

    newSum = 1*x + 2*a + 3*b + 4*c
           = [x + a + b + c] + OldSum

    gain = x + PrefixSum
    */
    for(int i = n - 1; i>= 0; i--){
      prefSum += s[i];

      if(prefSum <= 0){
        break;
      }

      ans += prefSum;
    }
    return ans;
    }
};