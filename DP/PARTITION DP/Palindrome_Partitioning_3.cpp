#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:

  // [st.....end] | [end+1.....n-1]
  //   one piece      remaining piece

  int n;
  int dp[101][101];
  vector<vector<int>> cost;

  // f(i,k) = starting from i, min cost to partition suff[i..n-1] into k palindromic partitions 

  int f(int i, int k){
    // No chars left, no pali left to make 
    if(i == n && k == 0) 
      return 0;

    // Chars finished, still need pali
    // Splits finished, chars left 
    if(i == n || k == 0)
      return INF;

    if(k > n - i) // Not enough chars 
      return INF;

    if(dp[i][k] != -1)
      return dp[i][k];

    int ans = INF;

    for(int j = i; j < n; j++)
      ans = min(ans, cost[i][j] + f(j + 1, k - 1));

    return dp[i][k] = ans;
  }

  int palindromePartition(string s, int k) {
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cost.assign(n, vector<int> (n, 0));

    for(int len = 2; len <= n; len++){
      for(int l = 0; len + l - 1 < n; l++){
        // len = j - i + 1
        // j = len + i - 1
        int r  = len + l - 1;

        if(len == 2)
          cost[l][r] = (s[l] != s[r]); // changes needed if chars are differnt
        else
          cost[l][r] = cost[l+1][r-1] + (s[l] != s[r]); 
      }
    }

    int ans = f(0, k);

    return ans;
  }
};