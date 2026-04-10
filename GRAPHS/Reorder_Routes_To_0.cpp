#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS 
//* TC = O(V + E) || SC = O(V + E)

class Solution {
public:
  int cnt = 0;
  void dfs(int node, int parent, vector<pair<int,int>> adj[]){
    for(auto &p : adj[node]){
      int adjNode = p.first;
      int isRealEdge = p.second;

      if(adjNode == parent) continue; // Avoid cycle

      if(isRealEdge){
        cnt++;
      } 

      dfs(adjNode, node, adj);
    }
  }

  int minReorder(int n, vector<vector<int>>& edges) {
  vector<pair<int,int>> adj[n];

  for(auto &e: edges){
    int u = e[0];
    int v = e[1];

    adj[u].push_back({v,1}); // Real edge
    adj[v].push_back({u,0}); // Fake edge - created by us
  }
  
  /*
  We are going from 0 to other nodes.
  If real edge is goes from u -> v cnt++ cause we need to reverse it to come towards 0
  */

  dfs(0,-1,adj);

  return cnt;
  }
};

//! BFS

class Solution {
public:
  int minReorder(int n, vector<vector<int>>& edges) {
  vector<pair<int,int>> adj[n];

  for(auto &e: edges){
    int u = e[0];
    int v = e[1];

    adj[u].push_back({v,1}); // Real edge
    adj[v].push_back({u,0}); // Fake edge - created by us
  }
  
  /*
  We are going from 0 to other nodes.
  If real edge is goes from u -> v cnt++ cause we need to reverse it to come towards 0
  */
  vector<bool> vis(n, 0);
  queue<int> q;

  q.push(0);
  vis[0] = 1;

  int cnt = 0;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(auto &it : adj[node]){
      int nei = it.first;
      int isRealEdge = it.second;

      if(vis[nei]) continue;

      if(isRealEdge) cnt++; // Its going away from 0, should be towards

      vis[nei] = 1;
      q.push(nei);
    }
  }

  return cnt;
  }
};