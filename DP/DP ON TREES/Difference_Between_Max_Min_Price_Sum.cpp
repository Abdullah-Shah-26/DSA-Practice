#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// In - Out DP

class Solution {
public:
  vector<vector<int>> adj;
  vector<int> price;
  vector<ll> maxIn, maxOut;

  // Max subtree sum among all paths downwards from root
  ll InDfs(int u, int p) {

    for (auto v : adj[u]) {
      if (v == p)
        continue;

      maxIn[u] = max(maxIn[u], InDfs(v, u));
    }
    maxIn[u] += price[u];

    return maxIn[u];
  }

  // MaxOut[u] = best path starting at u and going upward/outside subtree of u
  void OutDfs(int u, int p) {
    multiset<ll> InOfAll;

    for (auto v : adj[u])
      if (v != p)
        InOfAll.insert(maxIn[v]);

    for (auto v : adj[u]) {
      if (v == p)
        continue;

      ll curVal = maxIn[v];

      InOfAll.erase(InOfAll.find(curVal));

      ll below = InOfAll.empty() ? 0 : *(--InOfAll.end());
      maxOut[v] = max(maxOut[u], below) + price[u]; // Since MaxOut or InOfAll doesnt include price of parent

      InOfAll.insert(curVal);
      OutDfs(v, u);
    }
  }

  long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &p) {
    adj.assign(n, {});
    maxIn.assign(n, 0);
    maxOut.assign(n, 0);
    price.assign(n, 0);

    for (int i = 0; i < p.size(); i++)
      price[i] = p[i];

    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    InDfs(0, -1);
    OutDfs(0, -1);

    ll ans = 0;

    for (int root = 0; root < n; root++) {
      ll val = max(maxIn[root], maxOut[root] + price[root]) - price[root];
      ans = max(ans, val);
    }

    return ans;
  }
};