#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N alpha(N))  ||  SC = O(N)          N = r + c

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
    int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int maxR = 0;
    int maxC = 0;

    for(auto it : stones){
      int r = it[0];
      int c = it[1];
      maxR = max(maxR, r);
      maxC = max(maxC, c);
    }     

    DSU dsu(maxR + maxC + 2);

    unordered_map<int,int> stoneNodes; // Active Nodes
    
    for(auto it : stones){
      int r = it[0];
      int c = it[1];
      int nodeRow = r;
      int nodeCol = c + maxR + 1;

      dsu.unite(nodeRow, nodeCol);
      stoneNodes[nodeRow] = 1;
      stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for(auto &it: stoneNodes){
      if(dsu.find(it.first) == it.first){
        cnt++;
      }
    } 

    return n - cnt;
    }
};
