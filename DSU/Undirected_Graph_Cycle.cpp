#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC =  O(E alpha(V))  || SC = O(V)

struct DSU{
    vector<int> parent, size;
    
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);
        
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x){
        if(x == parent[x]) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void merge(int u,int v){
        u = find(u);
        v = find(v);
        
        if(u == v) return;
        
        if(size[u] < size[v]) swap(u,v);
        
        parent[v] = u;
        size[u] += size[v]; 
    }
};


class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        DSU ds(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            if(ds.find(u) == ds.find(v)) return true;
            
            ds.merge(u,v);
        }
    return false;
    }
};