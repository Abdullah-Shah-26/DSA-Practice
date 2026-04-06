#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N*M)Log(N*M)  ||   SC = O(N*M)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};


class Solution {
public:
    int n, m;
    int row[4] = {0, 0, 1, -1};
    int col[4] = {1, -1, 0, 0};
    
    int minimumEffortPath(vector<vector<int>>& mat) {
    n = mat.size();
    m = mat[0].size();

    vector<tuple<int,int,int>> edges; // wt, u, v

    auto id = [&](int r, int c){
      return r*m + c;
    };

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        // Since graph is undirected u-v is same as v-u
        // So we just connect right & down
        if(i + 1 < n){
          int wt = abs(mat[i][j] - mat[i+1][j]);
          edges.push_back({wt, id(i,j), id(i + 1, j)});
        }

        if(j + 1 < m){
          int wt = abs(mat[i][j] - mat[i][j+1]);
          edges.push_back({wt, id(i,j), id(i, j+1)});
        }

      }
    }

    sort(edges.begin(),edges.end());

    DSU ds(n*m);

    for(auto &[w,u,v] : edges){
      ds.unite(u,v);
      //* The Last Edge That Connects st & end will be max possible min edge   
      if(ds.find(0) == ds.find(n*m  - 1)){
        return w;
      }
    }

    return 0;
    }
};