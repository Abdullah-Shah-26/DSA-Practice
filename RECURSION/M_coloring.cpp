#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Try to color vertex 'idx' (and all beyond it)
  bool backtrack(int idx,
         int v,
         int m,
         vector<int>& color,
         vector<vector<int>>& adj)
  {
    if (idx == v) 
      return true;              // all vertices colored successfully

    // Try each of the m colors for vertex idx
    for (int c = 0; c < m; ++c) {
      bool safe = true;
      // verify no neighbor has color c
      for (int nei : adj[idx]) {
        if (color[nei] == c) {
          safe = false;
          break;
        }
      }
      if (!safe) continue;

      // assign and recurse
      color[idx] = c;
      if (backtrack(idx + 1, v, m, color, adj))
        return true;
      // backtrack
      color[idx] = -1;
    }
    return false;  // no valid color found for idx
  }

  bool graphColoring(int v, vector<vector<int>>& edges, int m) {
    // 1) Build adjacency list
    vector<vector<int>> adj(v);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    // 2) Prepare color array
    vector<int> color(v, -1);

    // 3) Launch vertex-by-vertex backtracking
    return backtrack(0, v, m, color, adj);
  }
};

//!------------------------

class Solution {
public:
  bool find(int node, vector<vector<int>> &adj, int n, int m, vector<int> &color) {
    // Base case: All nodes are colored
    if (node == n)
      return true;
        
    // Try all m colors for this node
    for (int c = 0; c < m; ++c) {
      bool safe = true;
      // Check if any neighbor of 'node' already has the color 'c'
      for (int nei : adj[node]) {
        if (color[nei] == c) {
          safe = false;
          break;
        }
      }
      if (safe) {
        color[node] = c;
        // Move to the next node, return true if successful
        if (find(node + 1, adj, n, m, color))
          return true;
        // Backtrack on failure
        color[node] = -1;
      }
    }
    // Return false if no color can be assigned to this node
    return false;
  }
    
  bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    vector<int> color(v, -1);
    vector<vector<int>> adj(v);
    // Build the adjacency list
    for (auto &e : edges) {
      // Assuming each edge e is a pair {u, v}
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    // Start the coloring process from node 0
    return find(0, adj, v, m, color);
  }
};