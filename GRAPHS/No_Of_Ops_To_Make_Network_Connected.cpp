#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS - Recursive
//* TC = O(V + E)  || SC = O(V) 

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool>&vis){
      vis[node] = 1;

      for(auto &nei : adj[node]){
        if(!vis[nei]){
          dfs(nei, adj, vis);
        }
      }
    }

    int makeConnected(int n, vector<vector<int>>& edges) {
    
    if(edges.size() < n - 1) return -1;

    int components = 0;

    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> vis(n,0);

    for(int i = 0; i < n; i++){
      if(!vis[i]){
        components++;
        dfs(i, adj, vis);
      }
    }

    return components - 1;
    }
};

//! DFS Iterative

class Solution {
public:
    void dfsIt(int start, vector<vector<int>> &adj, vector<bool> &vis){
      stack<int> st;
      st.push(start);
      
      while(!st.empty()){
        int node = st.top();
        st.pop();

        if(vis[node]) continue;

        vis[node] = 1;

        for(auto &nei : adj[node]){
          if(!vis[nei]){
            st.push(nei);
          }
        }
      }
    }

    int makeConnected(int n, vector<vector<int>>& edges) {
    
    if(edges.size() < n - 1) return -1;

    int components = 0;

    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> vis(n,0);

    for(int i = 0; i < n; i++){
      if(!vis[i]){
        components++;
        dfsIt(i, adj, vis);
      }
    }

    return components - 1;
    }
};

//! BFS 

class Solution {
public:
    void bfs(int st, vector<vector<int>> &adj, vector<bool> &vis){
      queue<int> q;
      q.push(st);
      vis[st] = 1;

      while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &nei : adj[node]){
          if(!vis[nei]){
            vis[nei] = 1;
            q.push(nei);
          }
        }
      }

    }

    int makeConnected(int n, vector<vector<int>>& edges) {
    
    if(edges.size() < n - 1) return -1;

    int components = 0;

    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> vis(n,0);

    for(int i = 0; i < n; i++){
      if(!vis[i]){
        components++;
        bfs(i, adj, vis);
      }
    }

    return components - 1;
    }
};