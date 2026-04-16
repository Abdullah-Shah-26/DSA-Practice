#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }


// Interval DP
// TC = O(N^2)
// SC = O(N^2)

// TODO : Manacher Algo -> O(n) time and O(n) space 
class Solution {
public:
    int countSubstrings(string s) {
    int n = s.size();
    bool dp[n][n];
    // len = j - i + 1;
    // j = i + len - 1
    // i = j - len + 1;
    int cnt = 0;
    for(int len = 1; len <= n; len++){
      // i -> st idx
      for(int i = 0; i + len - 1 < n; i++){
        // j -> end idx
        int j = i + len - 1;
        if(len == 1){
          dp[i][j] = true; 
        }
        else if(len == 2){
          dp[i][j] = (s[i] == s[j]);
        }
        else{ // len > 2
          if(s[i] == s[j]){ // Extreme char should be equal + mid chars too
            dp[i][j] = (dp[i+1][j-1] == true);
          }
          else{ // s[i] != s[j];
            dp[i][j] = false;
          }
        }
        cnt += dp[i][j];
      }
    }
    return cnt;
    }
};