//! Functional Graph

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

class Solution
{
public:
  vector<int> edges, ans, vis;

  void dfs(int u)
  {
    if (vis[u] == 2)
      return;

    if (vis[u] == 1)
    {
      // Calculate cycle Len
      int len = 1;
      int cur = edges[u];

      while (cur != u)
      {
        len++;
        cur = edges[cur];
      }

      // Assign Len to each cycle node
      cur = u;
      do
      {
        ans[cur] = len;
        cur = edges[cur];
        vis[cur] = 2;
      } while (cur != u);

      return;
    }

    vis[u] = 1;
    int v = edges[u];
    dfs(v);

    if (vis[u] != 2)
    {
      vis[u] = 2;
      ans[u] = ans[v] + 1;
    }
  }

  vector<int> countVisitedNodes(vector<int> &e)
  {
    edges = e;
    int n = edges.size();

    ans.assign(n, 0);
    vis.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (vis[i] == 0)
      {
        dfs(i);
      }
    }
    return ans;
  }
};