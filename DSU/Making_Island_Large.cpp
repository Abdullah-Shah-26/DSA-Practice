#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = (N*M alpha(N*M))  ||  SC = (N*M)

class DSU {
  public:
    vector<int> parent, size;
    
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return (x == parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    DSU dsu(n*m);

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    for(int r = 0; r < n; r++){
      for(int c = 0; c < m; c++){
        
        if(grid[r][c] == 0) continue;

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
            int node = r * m + c;
            int adjNode = nr * m + nc;

            dsu.unite(node, adjNode);
          }
        }
      }
    }
    // Find 0 and Flip it to 1 and compute size  
    int maxi = 0;
    for(int r = 0; r < n; r++){
      for(int c = 0; c < m; c++){

        if(grid[r][c] == 1) continue;
        unordered_set<int> comp;

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
            comp.insert(dsu.find(nr * m + nc));
          }
        }

        int totalSize = 0;
        for(auto &it : comp){
          totalSize += dsu.size[it];
        }

        maxi = max(maxi, totalSize + 1); // +1 for guy that converted from 0->1
      }
    }

    maxi = max(maxi, dsu.size[dsu.find(0)]);
    return maxi;    
    }
};
