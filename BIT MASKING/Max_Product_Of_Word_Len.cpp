#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Bit Masking 26 characters
class Solution {
public:
    int maxProduct(vector<string>& words) {
    vector<int>masks(words.size());
    int n = words.size();
    for(int i = 0; i < n; i++){
      int mask = 0;
      for(char ch : words[i]){
        mask |= (1 << (ch - 'a'));
      }
      masks[i] = mask;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if((masks[i] & masks[j]) == 0){
          ans = max(ans,(int)words[i].size() * (int)words[j].size());
        }
      }
    }
    return ans;
    }
};