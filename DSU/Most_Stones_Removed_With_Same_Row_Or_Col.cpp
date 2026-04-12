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
    int maxR = 0, maxC = 0;

    for(auto &s : stones){
      int r = s[0];
      int c = s[1];

      maxR = max(maxR, r);
      maxC = max(maxC, c);
    }    

    DSU dsu(maxR + maxC + 2);

    unordered_set<int> usedNodes;

    for(auto &s : stones){
      int r = s[0];
      int c = s[1];
      int nodeRow = r;
      int nodeCol = c + maxR + 1;

      dsu.unite(nodeRow, nodeCol);
      usedNodes.insert(nodeRow);
      usedNodes.insert(nodeCol);
    }

    int groups = 0;

    for(auto &it : usedNodes){
      if(dsu.find(it) == it) 
        groups++;
    }

    return n - groups;
    }
};

//! DFS
//!* TC = O(N^2) | SC = O(N)

class Solution {
  public:
    void dfs(int idx, vector<vector<int>> &stones, vector<bool> &vis){
      vis[idx] = 1;
      int r = stones[idx][0];
      int c = stones[idx][1];

      for(int i = 0; i < stones.size(); i++){
        if(!vis[i] && (r == stones[i][0] || c == stones[i][1])){
          dfs(i, stones, vis);
        }
      }
    }

    int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int groups = 0;

    vector<bool> vis(n, false);

    for(int i = 0; i < n; i++){
      if(!vis[i]){
        dfs(i, stones, vis);
        groups++;
      }
    }    

    return n - groups;
    }
};
