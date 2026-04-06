#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(E alpha(V))  || SC = O(V)

class DSU {
public:
    vector<int> parent, rank;
    int components;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        components = n;

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;

        if (rank[u] < rank[v]) swap(u, v);

        parent[v] = u;

        if (rank[u] == rank[v])
            rank[u]++;

        components--;
        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
    if(edges.size() < n-1) return -1;
      
    DSU ds(n);

    for(auto &e : edges){
      ds.unite(e[0], e[1]);
    }
    // We need n-1 edges to connect n components
    return ds.components - 1;
    }
};