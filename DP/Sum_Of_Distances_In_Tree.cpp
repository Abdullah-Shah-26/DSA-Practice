#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N) | SC = O(N)

class Solution {
  public:
    //* 1. Compute Subtree sizes + root distance sum
    int computeSubTree(int node, int parent, vector<vector<int>> &adj, vector<int> &subTreeSize, int depth, int &rootDistSum){
      
      int size = 1;
      rootDistSum += depth;

      for(int nei : adj[node]){
        if(nei == parent) continue;

        size += computeSubTree(nei, node, adj, subTreeSize, depth + 1, rootDistSum);
      }

      subTreeSize[node] = size;
      return size;

    }

    //* 2. Reroot DP
    void reroot(int node, int parent, vector<vector<int>> &adj, vector<int> &subTreeSize, vector<int> &distSum, int n){

      for(int nei : adj[node]){
        if(nei == parent) continue;

        distSum[nei] = distSum[node] - subTreeSize[nei] + (n - subTreeSize[nei]);

        reroot(nei, node, adj, subTreeSize, distSum, n);
      }
    }
    

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }    

    vector<int> subTreeSize(n, 0);
    vector<int> distSum(n, 0);

    int rootDistSum = 0;

    computeSubTree(0, -1, adj, subTreeSize, 0, rootDistSum);

    distSum[0] = rootDistSum;

    reroot(0, -1, adj, subTreeSize, distSum, n);

    return distSum;
    }
};