#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

// TC = O(N * K^2) | SC = O(N * K * 2)

class Solution {
public:
  int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
    int n = parent.size();

    vector<vector<int>> adj(n);
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (k, vector<ll> (2, 0)));

    // dp[i][j][0] = No of subsets whose sum % k = j & node i isnt selected in these subsets
    // dp[i][j][1] = No of subsets whose sum % k = j & node i is selected in these subsets

    for(int i = 1; i < n; i++)
      adj[parent[i]].push_back(i);

    function<void(int)> dfs = [&](int p){
      dp[p][0][0] = 1; 
      dp[p][nums[p] % k][1] = 1;

      for(int v : adj[p]){
        dfs(v);

        vector<vector<ll>> temp(k, vector<ll> (2, 0));

        for(int i = 0; i < k; i++){
          for(int j = 0; j < k; j++){ 

            // Parent p is NOT selected, so child v may be selected OR not selected.
            temp[(i + j) % k][0] = (temp[(i + j) % k][0] + ((dp[v][i][0] + dp[v][i][1])* dp[p][j][0]) % MOD) % MOD;

            // p selected -> child cannot be selected
            temp[(i + j) % k][1] = (temp[(i + j) % k][1] + (dp[v][i][0] * dp[p][j][1] % MOD)) % MOD;
          }
        }

        dp[p] = temp;
      }
    };

    dfs(0);

    return (dp[0][0][0] + dp[0][0][1] - 1 + MOD) % MOD;     
  }
};