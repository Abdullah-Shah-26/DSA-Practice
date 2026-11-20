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

vvll multiply(vvll &A, vvll &B) {
  int n = A.size();

  vvll C(n, vll(n, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

  return C;
}

vvll matExpo(vvll base, ll exp) {

  int n = base.size();

  vvll ans(n, vll(n, 0));

  // Identity matrix
  for (int i = 0; i < n; i++)
    ans[i][i] = 1;

  while (exp) {
    if (exp & 1) {
      ans = multiply(ans, base);
    }

    base = multiply(base, base);
    exp >>= 1;
  }

  return ans;
}

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  vvll T(m, vll(m, 1));

  auto getId = [](char ch) {
    if (ch >= 'a' && ch <= 'z')
      return ch - 'a';

    return ch - 'A' + 26;
  };

  while (k--) {
    char x, y;
    cin >> x >> y;

    int i = getId(x);
    int j = getId(y);

    // Forbidden pair
    T[i][j] = 0;
  }

  if (n == 1) {
    cout << m << endl;
    return;
  }

  vll b(m, 1);
  vvll mat = matExpo(T, n - 1);

  vll ans(m, 0);

  for (int j = 0; j < m; j++) {
    for (int i = 0; i < m; i++) {
      ans[j] = (ans[j] + b[i] * mat[i][j]) % MOD;
    }
  }

  ll res = 0;
  for (auto x : ans)
    res = (res + x) % MOD;

  cout << res << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}