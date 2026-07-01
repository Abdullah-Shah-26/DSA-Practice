#include <bits/stdc++.h>
using namespace std;

// Binary Lifting + Fenwick Tree + Euler Tour 
// TC = O(NLogN + QLogN)
// SC = O(NLogN) 

class Fenwick{
public:
  int n;
  vector<int> bit;

  Fenwick(int n){
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void update(int i, int val){
    while(i <= n){
      bit[i] ^= val;
      i += (i & -i);
    }
  }

  int query(int i){
    int ans = 0;

    while(i > 0){
      ans ^= bit[i];
      i -= (i & -i);
    }
    
    return ans;
  }
};

class Solution {
public:
  static const int LOG = 17;

  vector<vector<int>> adj;
  vector<vector<int>> up;

  vector<int> depth;
  vector<int> in;
  vector<int> out;
  
  int timer = 0;

  void dfs(int u, int p){
    in[u] = ++timer;
    up[u][0] = p;

    for(int v : adj[u]){
      if(v == p)
        continue;

      depth[v] = depth[u] + 1;
      dfs(v, u);
    }

    out[u] = timer;
  }

  int kthAncestor(int node, int k){
    for(int j = LOG-1; j >= 0; j--){
      if(k & (1 << j))
        node = up[node][j];
    }
    return node;
  }

  int LCA(int u, int v){
    if(depth[u] < depth[v])
      swap(u,v);

    u = kthAncestor(u, depth[u] - depth[v]);

    if(u == v)
      return u;

    for(int k = LOG-1; k >= 0; k--){
      if(up[u][k] != up[v][k]){
        u = up[u][k];
        v = up[v][k];
      }
    }

    return up[u][0];
  }

  vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
    adj.assign(n, {});
    up.assign(n, vector<int> (LOG, -1));
    depth.assign(n, 0);
    in.assign(n, 0);
    out.assign(n, 0);

    for(auto &e : edges){ // O(N)
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(0, -1); // O(N)

    for(int i = 0; i < n; i++){ // O(LogN)
      for(int k = 1; k < LOG; k++){
        if(up[i][k-1] != -1)
          up[i][k] = up[up[i][k-1]][k-1];
      }
    }

    Fenwick ft(n);

    for(int i = 0; i < n; i++){ // O(NLogN)
      int cur = 1 << (s[i] - 'a');
      ft.update(in[i], cur); // O(LogN)
      ft.update(out[i] + 1, cur);
    }

    vector<bool> ans;
    
    // Palindrome cond'n :
    // Even no of chars 
    // 0/1 Odd chars
    // Use xor, if even char it becomes 0
    // If odd char it becomes 1
    // If cur == 0, all even chars = isPalindrome
    // If cur has 1 bit set i.e have 1 odd char
    // Ex : 16 = 10000, 32 = 100000
    // (n & (n-1)) == 0, is power of 2 == isPalindrome 

    for(auto &q : queries){
      string type;
      stringstream ss(q);
      ss >> type;

      if(type == "update"){
        int u;
        char c;
        ss >> u >> c;
        int diff = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
        s[u] = c;
        ft.update(in[u], diff);
        ft.update(out[u] + 1, diff);
      }
      else{
        int u, v;
        ss >> u >> v;
        int lca = LCA(u, v);

        // ft.query(in[x]) gives prefix xor from root to node x

        // root --> LCA --> u
        // root --> LCA --> v
        // Common prefix (root -> LCA) gets canceled.
        // LCA is also canceled, so add its character back.

        int cur = ft.query(in[u]) ^ ft.query(in[v]) ^ (1 << (s[lca] - 'a'));
        ans.push_back(cur == 0 || (cur & (cur - 1)) == 0);
      }
    }

    return ans;
  }
};