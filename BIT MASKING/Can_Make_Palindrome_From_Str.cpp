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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int n = (int)s.size();

    vector<int>pref(n + 1, 0);
    // Bitmask prefix 
    for(int i = 0; i  < n; i++){
      pref[i + 1] = pref[i] ^ (1 << (s[i]-'a'));
    }
    vector<bool>ans;
    for(auto &q : queries){
      int l = q[0], r = q[1], k = q[2];
      int mask = pref[r + 1] ^ pref[l];
      int oddCnt = __builtin_popcount(mask);
      // Even Len pali - all Even OddCnt = 0
      // Odd Len pali - Atmost one Odd,Can reduce rest of the odd
      ans.push_back(oddCnt/2 <= k);
      } 
    return ans;
    }
};
