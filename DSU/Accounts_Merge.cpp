#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* V = Accounts , E = emails
//! TC = O(E Log E)  ||   SC = O(V + E)

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
    int n = acc.size();
    DSU dsu(n);

    unordered_map<string, int> owner; // email -> acc Idx

    for(int i = 0; i < n; i++){
      for(int j = 1; j < acc[i].size(); j++){
        string &email = acc[i][j];

        if(!owner.count(email)){
          owner[email] = i;
        }
        else{
          dsu.unite(owner[email], i);
        }
      }
    }

    vector<string> groups[n];

    for(auto &[email, idx] : owner){
      int root = dsu.find(idx);
      groups[root].push_back(email);
    }

    vector<vector<string>> res;

    for(int i = 0; i < n; i++){
      if(groups[i].empty()) continue;

      sort(groups[i].begin(), groups[i].end());

      res.push_back({acc[i][0]}); // name
      res.back().insert(res.back().end(), groups[i].begin(), groups[i].end());
    }

    return res;
    }
};