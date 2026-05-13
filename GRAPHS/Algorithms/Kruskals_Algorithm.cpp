#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(E Log E) + E(alpha(V))
//* SC = O(V)

class DSU{
    public:
    
    vector<int>parent, sz;
    
    DSU(int n){
        parent.resize(n,0);
        sz.resize(n,1);
        
        for(int i = 1;i < n; i++) parent[i] = i;
    }
    
    int find(int node){
        
        while(node != parent[node]){
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        
        return node;
    }
    
    bool unite(int u,int v){
        u = find(u);
        v = find(v);
        
        if(u == v) return 0;
        
        if(sz[u] < sz[v]) swap(u,v);
        
        parent[v] = u;
        sz[u] += sz[v];
        
        return 1;
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
    DSU ds(V);
    
    auto cmp = [&](vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    };
    
    sort(edges.begin(), edges.end(), cmp);
    int sum = 0;
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        
        if(ds.unite(u,v)){
            sum += w;
        }
    }
    
    return sum;
    }
};