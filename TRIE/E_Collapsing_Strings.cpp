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

LCP(rev(a),  s)

==========================
*/

class TrieNode {
 public:
  int cnt;
  TrieNode* child[26];

  TrieNode() {
    cnt = 0;

    for (int i = 0; i < 26; i++) child[i] = NULL;
  }
};

class Trie {
 private:
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string& s) {
    TrieNode* cur = root;

    for (int i = (int)s.size() - 1; i >= 0; i--) {
      int idx = s[i] - 'a';

      if (cur->child[idx] == NULL) cur->child[idx] = new TrieNode();

      cur = cur->child[idx];
      cur->cnt++;
    }
  }

  ll cntPrefix(string& s) {
    TrieNode* cur = root;
    ll ans = 0;

    for (char& ch : s) {
      int idx = ch - 'a';

      if (cur->child[idx] == NULL) break;

      cur = cur->child[idx];
      ans += cur->cnt;
    }

    return ans;
  }
};

void solve() {
  int n;
  cin >> n;

  Trie trie;

  ll totalLen = 0;

  vs words(n);

  for (int i = 0; i < n; i++) {
    cin >> words[i];

    trie.insert(words[i]);

    totalLen += (int)words[i].size();
  }

  ll ans = 2LL * n * totalLen;

  for (auto& s : words) {
    ans -= 2LL * trie.cntPrefix(s);
  }

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}