#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DSU + SPF 
//* TC = O(A Log(Log(A))) + N*LogA   (A = MaxElem)
//* SC = O(A + N)

class DSU{
  public:
  vector<int> parent, size;
  int components;

  DSU(int n){
    parent.resize(n,0);
    size.resize(n,1);
    components = n;

    for(int i = 1; i < n; i++) parent[i] = i;
  }

  int find(int x){
    return (x == parent[x]) ? x : parent[x] = find(parent[x]);
  }

  bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0; // No Merge Happened

    if(size[u] < size[v]) swap(u,v);

    parent[v] = u;
    size[u] += size[v];
    components--;

    return 1; // Merge Happened
  }
};

void buildSPF(vector<int> &spf, int maxi){
  for(int i = 0; i <= maxi; i++){
    spf[i] = i;
  }

  for(int i = 2; i*i <= maxi; i++){
    if(spf[i] == i){ // Its Prime, mark all the no's that it can divide
      for(int j = i*i; j <= maxi; j += i){
        if(spf[j] == j){ // Its unmarked
          spf[j] = i; // Mark it
        }
      } 
    }
  }
}

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
    int n = nums.size();
    
    // Edge Case
    if(n == 1) return true;

    int maxi = *max_element(begin(nums), end(nums));

    DSU dsu(n);

    vector<int> spf(maxi + 1);
    buildSPF(spf, maxi);

    vector<int> m(maxi + 1, -1); 

    auto process = [&](int factor, int i){ // factor, idx(owner)
      if(m[factor] != -1){
        dsu.unite(m[factor], i);
      }
      else{
        m[factor] = i;
      }
    };

    for(int i = 0; i < n; i++){
      int x = nums[i];

      if(x == 1) return false;

      while(x > 1){
        int factor = spf[x];

        process(factor, i);

        while(x % factor == 0){
          x /= factor;
        }
      }
    }

    return dsu.components == 1;
    }
};