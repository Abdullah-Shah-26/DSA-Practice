#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

  //! TC = O(N)
  //! SC = O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxLen = 0;
    int seen[256];
    memset(seen, -1, sizeof(seen));

    int l = 0, r = 0;

    while(r < n){
      char ch = s[r];

   
      if(seen[ch] != -1){ // Already seen 
        if(seen[ch] >= l){ // Its in our current window
          l = seen[ch] + 1;  // Shrink Invalid Window
        }
      }

      maxLen = max(maxLen, r - l + 1);
      seen[ch] = r;
      r++;
    }

    return maxLen;   
    }
};