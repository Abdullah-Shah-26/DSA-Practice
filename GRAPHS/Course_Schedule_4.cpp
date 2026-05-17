#include <bits/stdc++.h>
using namespace std;

// DFS / BFS ---> TC = O(N * Q) | SC = O(N)

class Solution {
public:
    bool dfs(vector<int> adj[], int src, int dst, vector<bool> &vis){
      vis[src] = 1;

      if(src == dst) return true;

      for(int nei : adj[src]){
        if(!vis[nei]){
          if(dfs(adj, nei, dst, vis)){
            return true;
          }
        }
      }
      return false;
    }

    bool bfs(vector<int> adj[], int src, int dst, vector<bool> &vis){
      vis[src] = 1;
      queue<int> q;
      q.push(src);

      while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == dst) return true;

        for(int nei : adj[node]){
          if(!vis[nei]){
            vis[nei] = 1;
            q.push(nei);
          }
        }
      }
      return false;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    vector<int> adj[n];

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
    }

    int q = queries.size();
    vector<bool> ans(q, 0);
    for(int i = 0; i < q; i++){
      
      auto &q = queries[i];
      int src = q[0];
      int dst = q[1];

      vector<bool> vis(n, 0);
      ans[i] = dfs(adj, src, dst, vis);
    }

    return ans;
    }
};

// Topo Sort + Transitive Dependecy
// TC = (V * (V + E))

class Solution {
  public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& qry) {
    vector<int> adj[n];
    vector<int> indeg(n, 0);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      indeg[v]++;
      adj[u].push_back(v);
    }    

    queue<int> q;
    for(int i = 0; i < n; i++){
      if(indeg[i] == 0){
        q.push(i);
      }
    }

    unordered_map<int, unordered_set<int>> mp;
    while(!q.empty()){
      int u = q.front();
      q.pop();

      for(int &v : adj[u]){
        mp[v].insert(u);

        // Transitive Dependency : {Guys} -> Node -> Nei, Guys that are prereq of Node are also prereq of Nei
        for(auto &preq : mp[u]){
          mp[v].insert(preq);
        }

        indeg[v]--;
        if(indeg[v] == 0){
          q.push(v);
        }
      }
    }

    int m = qry.size();
    vector<bool> ans(m);

    for(int i = 0; i < m; i++){
      int u = qry[i][0];
      int v = qry[i][1];

      ans[i] = mp[v].contains(u);
    }

    return ans;
    }
};