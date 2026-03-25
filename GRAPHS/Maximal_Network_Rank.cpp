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
    int maximalNetworkRank(int n, vector<vector<int>>& edges) {
    vector<vector<bool>> adjMat(n, vector<bool>(n,false));
    // No of nodes incident to each node
    vector<int> deg(n,0);
    for(auto &e : edges){ //! O(E)
      int u = e[0];
      int v = e[1];

      adjMat[u][v] = 1;
      adjMat[v][u] = 1;

      deg[u]++;
      deg[v]++;
    }
    int ans = 0;
    //! O(V^2)
    for(int u = 0; u < n; u++){
      for(int v = u + 1; v < n ; v++){
        ans = max(ans, deg[u] + deg[v] - adjMat[u][v]);
      }
    }    
    return ans;
    }
};