#include <bits/stdc++.h>
using namespace std;

// Reverse Hits + DSU + TrackSize
// TC = O(N*M + H) | SC = O(N*M)

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    int n = grid.size();
    int m = grid[0].size();

    int top = n*m; // Assumed virtual node

    vector<vector<int>> g = grid;

    for(auto &h : hits){
      int r = h[0];
      int c = h[1];

      if(g[r][c] == 1)
        g[r][c] = 0;
    }

    DSU dsu(n*m+1);

    auto id = [&](int r, int c){
      return r * m + c;
    };

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    // Building DSU on remaining grid
    for(int r = 0; r < n; r++){
      for(int c = 0; c < m; c++){
        if(g[r][c] == 0) continue;

        int u = id(r, c);

        // Any brick in row = 0 is stable
        if(r == 0)
          dsu.unite(u, top);


        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1){
            dsu.unite(u, id(nr, nc));
          }
        }
      } 
    }

    vector<int> res(hits.size(), 0);

    for(int i = hits.size() - 1; i >= 0; i--){
      int r = hits[i][0];
      int c = hits[i][1];

      // If original had no brick here - skip
      if(grid[r][c] == 0) continue;

      int before = dsu.size(top);

      // Add grid back
      int u = id(r, c);
      g[r][c] = 1;

      // Connect to top
      if(r == 0){
        dsu.unite(u, top);
      }

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1)
          dsu.unite(u, id(nr,nc));
      }

      int after = dsu.size(top);

      // Exclude the brick we just added
      res[i] = max(0, after - before - 1);
    
      // Bricks that beocme newly stable due to this addition are the ones that will fall when added brick is removed
    }

    return res;
    }
};