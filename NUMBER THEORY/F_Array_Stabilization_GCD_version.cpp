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

const int N = 1e6;

int spf[N + 1];

void buildSPF() {
  for (int i = 2; i <= N; i++)
    spf[i] = i;

  for (int i = 2; i * i <= N; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= N; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  int g = 0;

  for (int &x : a) {
    cin >> x;
    g = gcd(g, x);
  }

  for (int &x : a)
    x /= g;

  // (prime factor, arrIdx)
  vpii v;

  for (int i = 0; i < n; i++) {
    int x = a[i];

    while (x > 1) {
      int p = spf[x];
      v.pb({p, i});

      while (x % p == 0) {
        x /= p;
      }
    }
  }

  sort(all(v));

  int ans = 0;

  for (int i = 0; i < (int)v.size();) {
    int j = i;

    // Processing all indices of same prime
    while (j < (int)v.size() && v[j].first == v[i].first)
      j++;

    int cnt = 1;
    int best = 1;

    // Longest consecutive run of elements div by this prime
    for (int k = i + 1; k < j; k++) {
      if (v[k].second == v[k - 1].second) {
        cnt++;
      } else
        cnt = 1;

      best = max(best, cnt);
    }

    int m = j - i;
    cnt = 1;

    for(int k = 1; k < 2 * m; k++){
      int prev = v[i + (k - 1) % m].second;
      int cur = v[i + k % m].second;

      // Checking whether prev & cur are adjacent in orginal arr
      // %n cause we are also considering cirular arr
      if((prev + 1) % n == cur) cnt++;
      else cnt = 1;
      
      ans = max(ans, min(cnt, n));
    }

    ans = max(ans, best);
    i = j;
  }

  cout << ans << endl;
}

int main() {
  buildSPF();

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}