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
    int n;
    void dfs(int node, vector<bool>&vis, vector<vector<int>>&adj){
      vis[node] = 1;

      for(auto nei : adj[node]){
        if(!vis[nei]){
          dfs(nei, vis, adj);
        }
      }
    }

    bool canVisitAllRooms(vector<vector<int>>& adj) {
    n = adj.size();
    vector<bool>vis(n,0);
    dfs(0,vis,adj);    

    for(int i = 0; i < n; i++){
      if(!vis[i]) return false;
    }
    return true;
    }
};

//! BFS 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& adj) {
    int n = adj.size();    
    queue<int>q;
    vector<bool>vis(n,0);
    q.push(0);
    vis[0] = 1;

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

    for(int i =0; i < n; i++){
      if(!vis[i]) return 0;
    }
    return 1;
    }
};