#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N^2 * M)
//! SC = O(2*N)

struct DSU{
  vector<int>parent;
  vector<int>rank;
  DSU(int n){
    parent.resize(n,0);
    rank.resize(n);
    for(int i = 1; i <n; i++) parent[i] = i;
  } 
  int findUPar(int node){
    if(node == parent[node]){
      return node;
    }
    return parent[node] = findUPar(parent[node]);
  }

  void unionByRank(int u,int v){
    int ulp_u = findUPar(u); 
    int ulp_v = findUPar(v);

    if(rank[ulp_u] < rank[ulp_v]){
      parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v]){
      parent[ulp_v] = ulp_u;
    }
    else{
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};

class Solution {
public:
    bool isSimilar(string &s, string &t){
     int diff = 0;
     for(int i = 0; i < (int)s.size(); i++){
      if(s[i] != t[i]) diff++;
     }
     return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& words) {
    int n = words.size();
    int groups = n;
    DSU ds(n);

    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        if(isSimilar(words[i],words[j]) && ds.findUPar(i) != ds.findUPar(j)){
          ds.unionByRank(i,j);
          groups--;
        }
      }
    }
    return groups;
    }
};