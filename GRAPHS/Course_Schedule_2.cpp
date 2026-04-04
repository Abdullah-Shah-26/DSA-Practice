#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS - Khan's Algo

class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> inDeg(V);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[v].push_back(u);
      inDeg[u]++;
    }    

    queue<int> q;
    for(int i = 0; i < V; i++){
      if(inDeg[i] == 0){
        q.push(i);
      }
    }

    vector<int> ans;
    while(!q.empty()){
      int node = q.front();
      q.pop();

      ans.push_back(node);

      for(auto &nei : adj[node]){
        inDeg[nei]--;

        if(inDeg[nei] == 0){
          q.push(nei);
        }
      }
    }

    if(ans.size() == V) return ans;

    return {};
    }
};

//! DFS 

class Solution {
public:
    bool dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj){
      vis[node] = 1; // In Current Recursion

      for(auto &nei : adj[node]){
        if(vis[nei] == 0){
          if(dfs(nei, st, vis, adj)){
            return true;
          }
        }
        else if(vis[nei] == 1){
          return true;
        }
      }

      vis[node] = 2; // Fully Processed
      st.push(node);

      return false;
    }
    
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> vis(V,0);
    stack<int> st;

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      adj[v].push_back(u);
    }
    
    for(int i = 0; i < V; i++){
      if(vis[i] == 0){
        dfs(i, st, vis, adj);
      }
    }

    if(st.size() != V) return {};

    vector<int> ans;

    while(!st.empty()){
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
    }
};