#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 201;

class Solution {
public:
  ll dp[N][N];

  ll maxPrice(int r, int c, vector<vector<int>> &prices){
    if(r == 1 && c == 1) // Cannot split further 
      return prices[r][c];

    if(dp[r][c] != -1)
      return dp[r][c];

    ll ans = prices[r][c];

    // After cut, the transition represent new Ht or Width of the piece

    // Horizontal Split
    for(int row = 0; row < r/2; row++)
      ans = max(ans, maxPrice(row + 1, c, prices) + maxPrice(r - row - 1, c, prices));

    // Vertical Split
    for(int col = 0; col < c/2; col++)
      ans = max(ans, maxPrice(r, col + 1, prices) + maxPrice(r, c - col - 1, prices));

    return dp[r][c] = ans;
  }

  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> price(m + 1, vector<int> (n + 1, 0));
    
    for(auto &i : prices){
      int r = i[0];
      int c = i[1];
      int cost = i[2];

      price[r][c] = cost; // O(1) Lookup
    }

    return maxPrice(m, n, price);
  }
};