#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS 
//* TC = O(V + E) || SC = O(V + E)

class Solution {
  public:
    int n,m;
    pair<int,int> bfs(vector<int> adj[], int st){
      queue<int> q;
      q.push(st);

      vector<bool> vis(max(n + 1, m + 1),0);
      vis[st] = 1;

      int dist = 0;
      int farthest = st;

      while(!q.empty()){
        int size = q.size();

        while(size--){
          int node = q.front();
          q.pop();

          farthest = node;

          for(auto &nei : adj[node]){
            if(!vis[nei]){
              vis[nei] = 1;
              q.push(nei);
          }
        }
      }
      if(!q.empty()){
        dist++;
      }
    }

    return {farthest, dist};
  }

    int findDiameter(vector<int> adj[]){
      // Find farthest node(One end of diameter) from random node [0]
      auto [farthestNode1, dist] = bfs(adj, 0);

      // Find another Farthest node from this node (Other End of Diameter) 
      // The dist b/w then is diameter
      auto [farthestNode2, diameter] = bfs(adj, farthestNode1);

      return diameter;
    }
  
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    
    int maxNode = 0;
    for(auto &e : edges1){
      maxNode = max({maxNode, e[0], e[1]});
    }
    n = maxNode;

    maxNode = 0;
    for(auto &e : edges2){
      maxNode = max({maxNode, e[0], e[1]});
    }
    m = maxNode;

    vector<int> adj1[n + 1], adj2[m + 1];

    for(auto &e : edges1){
      int u = e[0];
      int v = e[1];

      adj1[u].push_back(v);
      adj1[v].push_back(u);
    }   

    for(auto &e : edges2){
      int u = e[0];
      int v = e[1];

      adj2[u].push_back(v);
      adj2[v].push_back(u);
    }

    int d1 = findDiameter(adj1);
    int d2 = findDiameter(adj2);

    // Diameter of tree when both of them are merged
    int combined = (d1+1)/2 + (d2+1)/2;
    // +1 - The edge that we added to combine them also counts
    return max({d1, d2, combined + 1});
    }
};

//! DFS Iterative

class Solution {
public:

    int getDiameter(vector<vector<int>> &adj, int root){
      int n = adj.size();
      int diameter = 0;

      vector<int> height(n,0); // ht of tree rooted at node

      stack<tuple<int,int,int>> st; // node, parent, state
      st.push({root, -1, 0});
    
      while(!st.empty()){
        auto [node, parent, state] = st.top();
        st.pop();

        if(state == 0){
        // First time visit
        // Process its children First

        st.push({node, parent, 1});

        for(auto &nei : adj[node]){
          if(nei == parent) continue; // Avoid going back

          st.push({nei, node, 0});
          }
        }
        else{
        // Second Visit
        // We know all ht's of children
        // Compute Diameter

        int max1 = 0, max2 = 0;

        for(auto &nei : adj[node]){
          if(nei == parent) continue;

          int h = height[nei];

          if(h > max1){
            max2 = max1;
            max1 = h;
          } 
          else if(h > max2){
            max2 = h;
          }
        }

        // Diameter = sum of 2 largest child heights
        diameter = max(diameter, max1 + max2);

        // Update ht of curNode
        height[node] = max1 + 1;
        }
      }

      return diameter;
    }

    vector<vector<int>> build(vector<vector<int>> &edges){
      int maxi = 0;

      for(auto &e : edges){
        maxi = max({maxi, e[0], e[1]});
      }

      vector<vector<int>> adj(maxi + 1);

      for(auto &e : edges){
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      return adj;
    }

    int solve(vector<vector<int>> &edges){
      if(edges.size() == 0) 
        return 0;

      auto adj = build(edges);

      return getDiameter(adj, edges[0][0]);
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
    int d1 = solve(e1);
    int d2 = solve(e2);

    int combined = (d1 + 1)/2 + (d2 + 1)/2 + 1;

    return max({d1, d2, combined});    
    }
};

//! DFs - Recursive 

class Solution {
public:
    int diameter;

    int dfs(int node, int parent, vector<vector<int>> &adj){
      int max1 = 0, max2 = 0;

      for(auto &nei : adj[node]){
        if(nei == parent) continue;

        int h = dfs(nei, node, adj);

        if(h > max1){
          max2 = max1;
          max1 = h;
        }
        else if(h > max2){
          max2 = h;
        }
      }

      // Ht of 2 Farthest Children from a node = Diameter
      diameter = max(diameter, max1 + max2);

      return max1 + 1; // Ht of curNode
    }

    int getDiameter(vector<vector<int>> &adj, int st){
      diameter = 0;
      dfs(st, -1, adj);

      return diameter;
    }

    vector<vector<int>> build(vector<vector<int>> &edges){
      int maxi = 0;

      for(auto &e : edges){
        maxi = max({maxi, e[0], e[1]});
      }

      vector<vector<int>> adj(maxi + 1);

      for(auto &e : edges){
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      return adj;
    }

    int solve(vector<vector<int>> &edges){
      if(edges.size() == 0) 
        return 0;

      auto adj = build(edges);

      return getDiameter(adj, edges[0][0]);
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
    int d1 = solve(e1);
    int d2 = solve(e2);

    int combined = (d1 + 1)/2 + (d2 + 1)/2 + 1;

    return max({d1, d2, combined});    
    }
};