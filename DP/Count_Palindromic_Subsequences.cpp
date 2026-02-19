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


class Solution {
  public:
   // Interval DP - Conventional Template
    int countPS(string &s) {
    int n = s.size();
    long long dp[n][n];
    // TC = O(N^2)
    // SC = O(N^2)
    
    // Current Substring Length
    for(int len = 1; len <= n; len++){
        // i = Starting idx
        for(int i = 0; i + len - 1 < n; i++){
            // j = Ending idx
            int j = i + len - 1;
            
            if(len == 1){
                dp[i][j] = 1;
            }
            else if(len == 2){
                // aa = a,a,aa
                // ab = a,b
                dp[i][j] = (s[i] == s[j]) ? 3 : 2;
            }
            else{
                if(s[i] == s[j]){
                // abc        
                // a, b, c
                dp[i][j] = ((dp[i][j-1] + dp[i+1][j])%MOD + 1)%MOD;
                }
                else{
                dp[i][j] = ((dp[i][j-1] + dp[i+1][j])%MOD - dp[i+1][j-1] + MOD)%MOD;
                }
            }
        }
      }
    return dp[0][n-1];
    }
};