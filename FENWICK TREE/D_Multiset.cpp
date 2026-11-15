#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

using ordered_set = tree<pii, null_type, less<pii>, rb_tree_tag,
                         tree_order_statistics_node_update>;

/*
==========================

Inserting as pair [value, id] allows us to store multiple occurences of same
value

(10, 0)
(20, 1)
(20, 2)

==========================
*/

/*

MLE

void solve() {
  ordered_set st;

  int n, q;
  cin >> n >> q;

  int id = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert({x, id});
    id++;
  }

  while (q--) {
    int k;
    cin >> k;

    // Insert value
    if (k > 0) {
      st.insert({k, id++});
    } else {
      // PBDS stores 0 based idx & k is 1 based
      auto it = st.find_by_order(abs(k) - 1);
      st.erase(it);
    }
  }

  if ((int)st.size() == 0)
    cout << 0 << endl;
  else
    cout << st.find_by_order(0)->first << endl;
}
*/

struct Fenwick {
  int n;
  vi bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  void update(int i, int val) {
    while (i <= n) {
      bit[i] += val;
      i += i & -i;
    }
  }

  // query[i] = pref sum from 1 to i
  int query(int i) {
    int sum = 0;

    while (i > 0) {
      sum += bit[i];
      i -= i & -i;
    }

    return sum;
  }

  // Binary lifting on Fenwick Tree

  // Kth smallest element
  int kth(int k) {
    int idx = 0;

    for (int pow = 1 << 20; pow > 0; pow >>= 1) {
      int nxt = idx + pow;

      // Largest idx where pref freq < k
      if (nxt <= n && bit[nxt] < k) {
        idx = nxt;
        k -= bit[nxt];
      }
    }

    return idx + 1;
  }
};

const int N = 1e6;

void solve() {
  Fenwick ft(N);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    ft.update(x, 1);
  }

  while (q--) {
    int k;
    cin >> k;

    if (k > 0) {
      ft.update(k, 1);
    } else {
      // Kth element
      int x = ft.kth(abs(k));

      // Remove it
      ft.update(x, -1);
    }
  }

  if (ft.query(N) == 0) {
    cout << 0 << endl;
  } else {
    cout << ft.kth(1) << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}