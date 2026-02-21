#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using ppi = pair<pair<int, int>, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

static const auto fastio = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

void solve()
{
  int n;
  cin >> n;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

class Solution
{
public:
  int mini = 1e9;
  int n;
  void solve(int idx, vector<int> &children, vector<int> &cookies, int k)
  {
    if (idx >= n)
    {
      int maxi = -1e9;
      for (auto &i : children)
        maxi = max(maxi, i);

      mini = min(mini, maxi);
      return;
    }
    int cookie = cookies[idx];
    for (int i = 0; i < k; i++)
    {
      children[i] += cookie;
      solve(idx + 1, children, cookies, k);
      children[i] -= cookie;

      if (children[i] == 0)
        break;
    }
  }

  int distributeCookies(vector<int> &cookies, int k)
  {
    vector<int> children(k);
    n = cookies.size();
    solve(0, children, cookies, k);

    return mini;
  }
};