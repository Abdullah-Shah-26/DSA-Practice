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

class TrieNode {
public:
  TrieNode *child[2];
  int cnt; // Each bit should know how many no's used it

  TrieNode() {
    child[0] = child[1] = NULL;
    cnt = 0;
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(int num) {
    TrieNode *cur = root;

    // MSB to LSB
    for (int i = 30; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if (cur->child[bit] == NULL)
        cur->child[bit] = new TrieNode();

      cur = cur->child[bit];
      cur->cnt++;
    }
  }

  void remove(int num) {
    TrieNode *cur = root;

    for (int i = 30; i >= 0; i--) {
      int bit = (num >> i) & 1;
      cur = cur->child[bit];
      cur->cnt--;
    }
  }

  int getMaxXor(int num) {
    TrieNode *cur = root;
    int ans = 0;

    for (int i = 30; i >= 0; i--) {
      int bit = (num >> i) & 1;

      // To maximize xor we need opposite bits
      if (cur->child[!bit] != NULL && cur->child[!bit]->cnt > 0) {
        ans |= (1 << i);
        cur = cur->child[!bit];
      } else if (cur->child[bit] != NULL && cur->child[bit]->cnt > 0) {
        cur = cur->child[bit];
      }
    }

    return ans;
  }
};

void solve() {
  Trie trie;

  // Initally insert 0
  // Given in problem stmt
  trie.insert(0);

  int q;
  cin >> q;

  while (q--) {
    char op;
    int x;
    cin >> op >> x;

    if (op == '+')
      trie.insert(x);
    else if (op == '-')
      trie.remove(x);
    else if (op == '?')
      cout << trie.getMaxXor(x) << endl;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}