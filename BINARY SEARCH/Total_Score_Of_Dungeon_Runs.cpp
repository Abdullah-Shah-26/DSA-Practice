#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Tricky problem : 

class Solution {
public:
  long long totalScore(int hp, vector<int>& d, vector<int>& r) {
    int n = d.size();    

    // d[j] + d[j + 1] + .... d[i] >= hp - req[i] 
    // pref[i] - pref[j - 1] >= hp - req[i]
    // pref[j - 1] >= pref[i] + req[i] - hp | [NEED] 

    vector<ll> pref(n + 1, 0);

    for(int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + d[i - 1];

    ll ans = 0;
    
    for(int i = 1; i <= n; i++){
      ll need = pref[i] + r[i - 1] - hp;

      // Possible starts pref[0 .... i - 1]
      int pos = lower_bound(pref.begin(), pref.begin() + i, need) - pref.begin();

      // Valid starts that give score of +1 each 
      ans += i - pos; 
    }

    return ans;
  }
};