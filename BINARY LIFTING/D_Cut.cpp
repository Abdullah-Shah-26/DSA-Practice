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

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

LCM == prod
When elements are coprime
Largest contigous group of coprime elements
Results in min no of subarraays

==========================
*/

const int N = 100005;
const int LOG = 20;

int a[N];
int last[N];
int nex[N];
int dp[N][LOG];

// factors[u] = distinct prime factors of u
vi factors[N];

void solve() {
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i = 2; i < N; i++) {
    if ((int)factors[i].empty()) {      // i is prime
      for (int j = i; j < N; j += i) {  // i is factor of its multiples
        factors[j].pb(i);
      }
    }
  }

  // last[p] = Idx of next occurrence of prime p
  for (int i = 2; i < N; i++) last[i] = n + 1;
  nex[n + 1] = n + 1;

  for (int i = n; i >= 1; i--) {
    nex[i] = nex[i + 1];

    for (auto p : factors[a[i]]) {
      nex[i] = min(nex[i], last[p]);
      last[p] = i;
    }
  }

  // dp[i][k] = pos reached from i after taking pow(2, k) jumps

  // nex[i] = After taking (1) pow(2, 0) jump from i we reach here
  for (int i = 1; i <= n + 1; i++) dp[i][0] = nex[i];

  // Going till (n + 1), It represents sentinel 
  for (int k = 1; k < LOG; k++) {
    for (int i = 1; i <= n + 1; i++) {
      dp[i][k] = dp[dp[i][k - 1]][k - 1];
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    int ans = 0;

    for (int k = LOG - 1; k >= 0; k--) {
      int next = dp[l][k];

      // 1 binary lifting jump = pow(2, k) normal jumps
      // We jump when cur valid subarr ends & to start next one
      if (next <= r) {
        ans += (1 << k);
        l = next;
      }
    }

    // Min no of subarrays needed
    // Such that [l..r] is divided in segments that have lcm == prod

    // No of subarrays = No of transitons + 1
    cout << ans + 1 << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}