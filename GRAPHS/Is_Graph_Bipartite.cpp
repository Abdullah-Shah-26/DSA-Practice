#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS 

class Solution {
public:
    bool bfs(int st, vector<int> &color, vector<vector<int>> &adj){
      color[st] = 0;

      queue<int> q;
      q.push(st);

      while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &nei : adj[node]){
          if(color[nei] == -1){
            color[nei] = !color[node];
            q.push(nei);
          }
          else if(color[nei] == color[node]) return false;
        }
      } 

      return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n,-1);

    for(int i = 0; i < n; i++){
      if(color[i] == -1){
        if(bfs(i, color, adj) == false){
          return false;
        }
      }
    }

    return true;
    }
};

//! DFS - Recursive

class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color){
      color[node] = col;
      
      for(auto &nei : adj[node]){
        if(color[nei] == -1){
          if(dfs(nei, !col, adj, color) == false){
            return false;
          }
        }
        else if(color[nei] == col){
          return false;
        }
      }
      return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++){
      if(color[i] == -1){
        if(dfs(i, 0, adj, color) == false) return false;
      }
    }

    return true;
    }
};

//! DFS - Iterative

class Solution {
public:
    bool dfsIt(int src, int iniColor, vector<vector<int>> &adj, vector<int> &color){
      color[src] = iniColor;
      stack<pair<int,int>> st;

      st.push({src, iniColor});

      while(!st.empty()){
        auto [node, col] = st.top();
        st.pop();

        for(auto &nei : adj[node]){
          if(color[nei] == -1){
            color[nei] = !col;
            st.push({nei, color[nei]});
          }
          else if(color[nei] == col){
            return false;
          }
        }
      }

      return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++){
      if(color[i] == -1){
        if(!dfsIt(i, 0, adj, color)) return false;
      }
    }

    return true;
    }
};