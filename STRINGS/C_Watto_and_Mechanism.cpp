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
using ull = unsigned long long;

const int INF = 1e9;
const ll LINF = 4e18;

const ll BASE1 = 31;
const ll BASE2 = 37;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define pv(a)                 \
  do {                        \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

Double Polynomial Rolling Hash

==========================
*/

const int maxL = 600005;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> words(n);

  for (string &s : words) {
    cin >> s;
  }

  vll power1(maxL + 1), power2(maxL + 1);

  power1[0] = 1;
  power2[0] = 1;

  for (int i = 1; i <= maxL; i++) {
    power1[i] = power1[i - 1] * BASE1 % MOD1;
    power2[i] = power2[i - 1] * BASE2 % MOD2;
  }

  vector<pll> hashes;

  for (string &s : words) {
    ll hash1 = 0;
    ll hash2 = 0;

    for (int i = 0; i < (int)s.size(); i++) {
      ll val = s[i] - 'a' + 1;

      hash1 = (hash1 + val * power1[i]) % MOD1;
      hash2 = (hash2 + val * power2[i]) % MOD2;
    }

    hashes.pb({hash1, hash2});
  }

  sort(all(hashes));

  while (m--) {
    string s;
    cin >> s;

    ll hash1 = 0;
    ll hash2 = 0;

    for (int i = 0; i < (int)s.size(); i++) {
      ll val = s[i] - 'a' + 1;

      hash1 = (hash1 + val * power1[i]) % MOD1;
      hash2 = (hash2 + val * power2[i]) % MOD2;
    }

    // Checks if we found a string that differs in only 1 position
    bool found = false;

    for (int i = 0; i < (int)s.size() && !found; i++) {
      ll oldVal = (s[i] - 'a' + 1);

      // Try to change this char to other 2 chars
      // a -> {b, c}
      // b -> {a, c}
      // c -> {a, b}
      for (ll newVal = 1; newVal <= 3; newVal++) {
        if (newVal == oldVal)
          continue;

        ll newHash1 = (hash1 + (newVal - oldVal) * power1[i]) % MOD1;
        ll newHash2 = (hash2 + (newVal - oldVal) * power2[i]) % MOD2;

        if (newHash1 < 0)
          newHash1 += MOD1;
        if (newHash2 < 0)
          newHash2 += MOD2;

        if (binary_search(all(hashes), make_pair(newHash1, newHash2))) {
          found = true;
          break;
        }
      }
    }

    if (found)
      YES;
    else
      NO;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}