#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DSU 
//* TC = O(V + E) 
//* SC = O(V)

class DSU{
  public: 
    int n;
    vector<int> parent, sz;
    
    DSU(int n){
        parent.resize(n,0);
        sz.resize(n,1);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(x == parent[x]) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    bool merge(int u, int v){
        u = find(u);
        v = find(v);
        
        if(u == v) return 0; // No merge happened
        
        if(sz[u] < sz[v]) swap(u,v);
        
        parent[v] = u; 
        sz[u] += sz[v];
        
        return 1; // merge happened
    }
};

class Solution {
  public:
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    vector<vector<int>> ans;
    vector<bool> vis(V, 0);
    
    DSU dsu(V);
    
    for(auto &e : edges){
        dsu.merge(e[0],e[1]);
    }
    
    unordered_map<int, vector<int>> comp;
    
    for(int i = 0; i < V; i++){
        int root = dsu.find(i);
        comp[root].push_back(i);
    }
    
    for(auto &it : comp){
        ans.push_back(it.second);
    }
        
    return ans;
    }
};
