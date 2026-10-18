#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;
using T = tuple<ll, ll, ll>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

void solve() {
  int n;
  cin >> n;

  vector<int> f(n), indeg(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
    indeg[f[i]]++;
  }

  vector<int> vis(n, 0);
  vector<int> leaves, ends;

  // 1. Trace chains starting from all sources
  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      int u = i;
      while (!vis[u]) {
        vis[u] = 1;
        u = f[u];
      }
      leaves.push_back(i);
      ends.push_back(u);
    }
  }

  // 2. Trace any remaining pure cycles (components with no sources)
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int u = i;
      while (!vis[u]) {
        vis[u] = 1;
        u = f[u];
      }
      leaves.push_back(i);
      ends.push_back(u);
    }
  }

  // Base case: If the whole graph is ALREADY exactly one perfect cycle
  if (leaves.size() == 1 && indeg[leaves[0]] > 0) {
    cout << 0 << '\n';
    return;
  }

  // Link all the chains into one continuous ring
  cout << leaves.size() << '\n';
  for (int i = 0; i < leaves.size(); i++) {
    int u = ends[i];
    int v = leaves[(i + 1) % leaves.size()];
    
    // Output 1-based indices
    cout << u + 1 << " " << v + 1 << '\n';
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}