#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N * alpha(26))  ||  SC = O(1)

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
    bool equationsPossible(vector<string>& equations) {
    int n = equations.size();    
    DSU dsu(26);

    for(auto &e : equations){
      if(e[1] == '='){
        dsu.unite(e[0] - 'a', e[3] - 'a');
      }
    }

    for(auto &e : equations){
      if(e[1] == '!'){
        if(dsu.find(e[0] - 'a') == dsu.find(e[3] - 'a')){
          return false;
        }
      }
    }

    return true;
    }
};