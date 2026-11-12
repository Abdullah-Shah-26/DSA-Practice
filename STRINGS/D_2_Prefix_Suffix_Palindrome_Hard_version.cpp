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

Longest Palindromic Prefix & 
Longest Palindromic Suffix 

==========================
*/

// Longest proper prefix suffix 
vi computeLPS(string& s) {
  int n = s.size();
  vi lps(n, 0);

  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];

    while (j > 0 && s[i] != s[j]) j = lps[j - 1];

    if (s[i] == s[j]) j++;

    lps[i] = j;
  }

  return lps;
}

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  int l = 0, r = n - 1;

  while (l < r && s[l] == s[r]) {
    l++;
    r--;
  }

  string outer = s.substr(0, l);
  string mid = s.substr(l, r - l + 1);

  string router = outer;
  reverse(all(router));

  string rmid = mid;
  reverse(all(rmid));

  // For middle part
  // Either it can be Longest Palindromic Prefix

  string S = mid + "#" + rmid;
  vi LPS = computeLPS(S); 
  int prefLen = LPS.back();

  // Or Longest Palindromic Suffix
  S = rmid + "#" + mid;
  LPS = computeLPS(S);
  int suffLen = LPS.back();

  if (prefLen >= suffLen) {
    mid = mid.substr(0, prefLen);
  } else {
    mid = mid.substr(mid.size() - suffLen);
  }

  cout << outer + mid + router << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}