#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void dfs(int val,vector<vector<int>>&adj)
{
  cout << val << "->";
  for(auto &i : adj[val])
  dfs(i,adj);
}

void solve() {
    int u,v,n,e;
    cin >> n >> e;
    vector<vector<int>>adj(n+1);

    while(e--)
    {
      cin >> u >> v;
      adj[u].push_back(v);
    }
    dfs(1,adj);
    return;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}