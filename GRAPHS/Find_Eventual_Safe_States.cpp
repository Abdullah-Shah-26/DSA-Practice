#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS
//* TC = O(V + E) || SC = O(V)

class Solution {
  public:
    bool dfs(int i, vector<int> &vis, vector<vector<int>> &adj){
      vis[i] = 1;// In Current Path

      for(auto &nei : adj[i]){
        if(vis[nei] == 0){
          if(dfs(nei, vis, adj)){
            return true;
          }
        }
        else if(vis[nei] == 1){
          // Cycle Exist 
          return true;
        }
      }

      vis[i] = 2; // Processed Completely
      return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n,0);

    for(int i = 0; i < n; i++){
      if(vis[i] == 0){
        dfs(i, vis, adj);
      }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
      if(vis[i] == 2) ans.push_back(i);
    }

    return ans;
    }
};

//! BFS 

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<vector<int>> adjRev(n);
    vector<int> inDeg(n,0);

    for(int node = 0; node < n; node++){
      for(auto &nei : adj[node]){
        adjRev[nei].push_back(node);
        inDeg[node]++;
      }
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
      if(inDeg[i] == 0){
        q.push(i);
      }
    }
    vector<int> ans;

    while(!q.empty()){
      int node = q.front();
      q.pop();
      ans.push_back(node);

      for(auto &nei : adjRev[node]){
        inDeg[nei]--;

        if(inDeg[nei] == 0){
          q.push(nei);
        }
      }
    }
    
    sort(begin(ans),end(ans));
    return ans;
    }
};