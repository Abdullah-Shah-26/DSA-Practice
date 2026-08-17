#include <bits/stdc++.h>
using namespace std;

// Tricky Greedy 

using ll = long long;

class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>>& cp) {

    vector<vector<ll>> lefts(n + 1);

    for(auto &it : cp){
      int l = min(it[0], it[1]);
      int r = max(it[0], it[1]);

      lefts[r].push_back(l);
    }     

    vector<ll> bonus(n + 1); // After removing the most strict criteria, the no of extra subarrays we gain
    ll ans = 0;
    ll max1 = 0, max2 = 0; 

    for(int r = 1; r <= n; r++){
      for(int l : lefts[r]){
        if(l > max1){
          max2 = max1;
          max1 = l;
        }
        else if(l > max2){
          max2 = l;
        }
      }

      ans += (r - max1); // Considering most strict criteria

      if(max1 > 0){
        bonus[max1] += (max1 - max2);
      }
    }

    ll maxBonus = *max_element(begin(bonus), end(bonus));

    return ans + maxBonus;
  }
};