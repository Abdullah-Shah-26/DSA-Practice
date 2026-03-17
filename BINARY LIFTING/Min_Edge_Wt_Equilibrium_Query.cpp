#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

/*
DFS : O(N)
Binary Lifting Build : O(N Log N)
Queries Processing   : O(Q Log N)
*/

class Solution {
public:
   static const int LOG = 17;
   vector<vector<pair<int,int>>> adj;
   vector<vector<int>> up;
   vector<vector<int>> freq;
   vector<int> depth;

    void dfs(int u,int p){
      for(auto &it : adj[u]){
        int v = it.first;
        int w = it.second;

        if(v == p) continue;

        depth[v] = depth[u] + 1;

        up[v][0] = u; // Filling Immediate parent

        freq[v] = freq[u];
        freq[v][w]++;

        dfs(v, u); 
      }
    }

    int KthAncestor(int node, int k){
      for(int bit = 0; bit < LOG; bit++){
        if(k & (1 << bit)){
          node = up[node][bit];

          if(node == -1) break;
        }
      }
      return node;
    }

    int lca(int a, int b){
      if(depth[a] < depth[b]) swap(a, b);

      int diff = depth[a] - depth[b];
      
      a = KthAncestor(a, diff);

      if(a == b) return a;

      for(int k = LOG - 1; k >= 0; k--){
        if(up[a][k] != up[b][k]){
           a = up[a][k];
           b = up[b][k];
        }
      }

      return up[a][0];
    }


    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    adj.assign(n, {});
    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      int w = e[2];

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    depth.assign(n, 0);
    up.assign(n, vector<int>(LOG, -1));
    freq.assign(n, vector<int>(27, 0));

    dfs(0, -1);

    for(int k = 1; k < LOG; k++){
      for(int node = 0; node < n; node++){
        if(up[node][k-1] != -1){
          up[node][k] = up[ up[node][k - 1]][k - 1];
        }
      }
    }

    vector<int>ans;

    for(auto &q : queries){
      int u = q[0];
      int v = q[1];
      int L = lca(u, v);

      int pathLen = depth[u] + depth[v] - 2 * (depth[L]);
      int maxFreq = 0;

      for(int w = 1; w <= 26; w++){
        int cnt = freq[u][w] + freq[v][w] - 2 * (freq[L][w]);
        maxFreq = max(maxFreq, cnt);
      }

      ans.push_back(pathLen - maxFreq);
    }

    return ans;
    }
};