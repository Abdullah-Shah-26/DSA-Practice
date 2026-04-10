#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS & BFS
//* TC = O(m * (V + E))  ||  SC = (V + E) + O(26)

class Solution {
  public:
  //! DFS
    char findMinChar(unordered_map<char, vector<char>> &adj, char ch, vector<bool> &vis){
      vis[ch-'a'] = 1;

      char minChar = ch;

      for(char &nei : adj[ch]){
        if(!vis[nei-'a']){
          minChar = min(minChar, findMinChar(adj, nei, vis));
        }
      }

      return minChar;
    }

  //! BFS
  char bfs(char st, vector<bool> &vis, unordered_map<char, vector<char>> &adj){
      char minChar = st;

      queue<char> q;
      
      q.push(st);
      vis[st-'a'] = 1;

      while(!q.empty()){
        char ch = q.front();
        q.pop();

        minChar = min(minChar, ch);

        for(auto &nei : adj[ch]){
          if(!vis[nei-'a']){
            vis[nei-'a'] = 1; 
            q.push(nei);
          }
        }
      }

      return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    int m = baseStr.size();

    unordered_map<char, vector<char>> adj;

    for(int i = 0; i < n; i++){
      char u = s1[i];
      char v = s2[i];

      adj[u].push_back(v);
      adj[v].push_back(u); 
    }

    string ans;

    for(int i = 0; i < m; i++){
      char ch = baseStr[i];

      vector<bool> vis(26, 0);

      char minChar = findMinChar(adj, ch, vis);

      ans.push_back(minChar);
    }

    return ans;
    }
};

//! DSU - Union by lexicographic minimum
//* TC = O(E alpha(V)) = (n alpha(26)) + m(alpha(26)) || SC = O(1)

class DSU{
  public:
  vector<int> parent;

  DSU(int n){
    parent.resize(n,0);
    
    for(int i = 0; i < n; i++) parent[i] = i;
  }

  int find(int x){
    return (x == parent[x]) ? x : parent[x] = find(parent[x]);
  }

  void unite(int u, int v){
    int ru = find(u);
    int rv = find(v);

    if(ru == rv) return;

    if(ru < rv){
      parent[rv] = ru;
    }
    else{
      parent[ru] = rv;
    }
  }

};

class Solution {
  public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    int m = baseStr.size();
    DSU dsu(26);

    for(int i = 0; i < n; i++){
      int u = s1[i]-'a';
      int v = s2[i]-'a';

      dsu.unite(u,v);
    }      

    string ans;
    for(char &ch : baseStr){
      ans += (dsu.find(ch-'a') + 'a');
    }

    return ans;
    }
};