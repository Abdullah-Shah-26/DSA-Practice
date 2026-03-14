#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    long long result = 0;
    unordered_map<int,int>m;
    
    void dfs(int node, int mask, vector<vector<pair<int,char>>> &adj){

    result += m[mask];

    for(int i = 0; i < 26; i++)
        result += m[mask ^ (1<<i)];

    m[mask]++;

    for(auto &it : adj[node]){
        int nxt = it.first;
        char ch = it.second;

        int newMask = mask ^ (1<<(ch-'a'));
        dfs(nxt, newMask, adj);
    }
}

    long long countPalindromePaths(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<pair<int,char>>>adj(n);

    for(int i = 1; i < n; i++){
      int p = parent[i];
      adj[p].push_back({i,s[i]});
    }   

    dfs(0, 0, adj);
    return result;
    }
};