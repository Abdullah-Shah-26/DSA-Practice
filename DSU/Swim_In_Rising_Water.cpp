#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N^2 Log N)  | SC = O(N^2)

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
  public:
    int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<tuple<int,int,int>> cells;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cells.push_back({grid[i][j], i, j});
      }
    }

    sort(begin(cells), end(cells));         
  
    DSU dsu(n*n);

    auto Id = [&](int r, int c){
      return r*n + c;
    };

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    vector<vector<bool>> active(n, vector<bool> (n, 0));

    for(auto &[val, r, c] : cells){ 
      active[r][c] = 1;

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0  && nc < n){
          if(active[nr][nc]){
            dsu.unite(Id(nr, nc), Id(r,c));
          }
        }
      }
     if(dsu.find(0) == dsu.find(n*n-1)){
      return val;
     }
    }

    return -1;
    }
};

//* Binary Search On Ans - Same TC | SC

class Solution {
  public:
    int n;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    bool possibleToReach(int i,int j, int t, vector<vector<int>> &grid, vector<vector<bool>> &vis){
      if(i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && grid[i][j] <= t){
        vis[i][j] = 1;

        if(i == n-1 && j == n-1) return true;

        for(int k = 0; k < 4; k++){
          int nr = i + row[k];
          int nc = j + col[k];

          if(possibleToReach(nr, nc, t, grid, vis)){
            return true;
          }
        }
      }

      return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
    n = grid.size();

    int l = grid[0][0];
    int r = n*n - 1;

    int ans = 0;

    while(l <= r){
      int mid = (l + r) >> 1;

      vector<vector<bool>> vis(n, vector<bool> (n, 0));
      if(possibleToReach(0, 0, mid, grid, vis)){
        ans = mid;
        r = mid - 1; 
      }
      else{
        l = mid + 1;
      }
    }    

    return ans;
    }
};