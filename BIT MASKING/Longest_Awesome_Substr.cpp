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
    int longestAwesome(string s) {
    // Store the idx where this state was seen first time
    int first[1024];
    fill(first, first + 1024, INT_MAX);
    first[0] = -1;    

    int ans = 0;
    int mask = 0;
    int n = (int)s.size();

    for(int i = 0; i < n; i++){
      int d = s[i] - '0';
      mask ^= (1 << d); 

      // For Even Len Palindromes - All Even 0 Odd
      if(first[mask] != INT_MAX){
        ans = max(ans, i - first[mask]);
      }

      // For Odd Len Palindroms - All Even and 1 Odd
      for(int b = 0; b < 10; b++){
        int m = mask ^ (1 << b);
        if(first[m] != INT_MAX){
          ans = max(ans,i - first[m]);
        }
      }

      if(first[mask] == INT_MAX){
        first[mask] = i;
      }
    }
    return ans;
    }
};