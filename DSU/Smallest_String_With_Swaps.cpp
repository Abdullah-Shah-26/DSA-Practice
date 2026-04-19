#include <bits/stdc++.h>
using namespace std;

//* TC = O(N log N)

struct DSU{
  vector<int> parent, size;

  DSU(int n){
    parent.resize(n, 0), size.resize(n,1);

    for(int i = 0; i < n; i++)
      parent[i] = i;
  }

  int find(int x){
    return (x == parent[x]) ? x : parent[x] = find(parent[x]);
  }  

  bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;

    if(size[u] < size[v])
      swap(u,v);

    size[u] += size[v];
    parent[v] = u;

    return 1; 
  }
};

class Solution {
  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    DSU dsu(n);

    for(auto &it : pairs){
      int l = it[0];
      int r = it[1];

      dsu.unite(l,r);
    }

    unordered_map<int, vector<int>> m;

    for(int i = 0; i < n; i++){
      int root = dsu.find(i);

      m[root].push_back(i);
    }

    for(auto& [root, indices] : m){

      vector<char> chars;

      for(auto &i : indices){
        chars.push_back(s[i]);
      }

      //* Smallest idx gets smallest available char
      sort(begin(chars), end(chars));
      sort(begin(indices), end(indices));

      // Overwrite
      for(int i = 0; i < indices.size(); i++){
        int idx = indices[i];
        s[idx] = chars[i];
      }
    }

    return s;
    }
};