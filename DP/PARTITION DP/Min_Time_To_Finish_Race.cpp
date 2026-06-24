#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:

  int changeTime;
  const ll INF = 1e18;
  vector<ll> best, dp;

  ll f(int lapsLeft){
    if(lapsLeft == 0) 
      return -changeTime; // Removing extra final change 

    if(dp[lapsLeft] != -1) 
      return dp[lapsLeft];

    ll ans = INF;

    for(int run = 1; run <= lapsLeft; run++){
      if(best[run] == INF) 
        break;

      ans = min(ans, best[run] + changeTime + f(lapsLeft - run));
    }

    return dp[lapsLeft] = ans;
  }

  int minimumFinishTime(vector<vector<int>>& tires, int changeT, int numLaps) {

    changeTime = changeT; 
    best.assign(numLaps + 1, INF);
    dp.assign(numLaps + 1, -1);

    // best[k] = pick 1 tire, use it k consecutive laps, No replacement
    // f(n) = min time to finish exactly n laps (Tire change allowed which takes +changeTime)
    
    for(auto &t : tires){
      ll fi = t[0];
      ll ri = t[1];
      ll lap = fi;
      ll total = 0;

      for(int k = 1; k <= numLaps; k++){
        total += lap;

        best[k] = min(best[k], total);
        if(lap * ri >= changeTime + fi)
          break;

        lap *= ri;
      }
    }

    return f(numLaps);
  }
};