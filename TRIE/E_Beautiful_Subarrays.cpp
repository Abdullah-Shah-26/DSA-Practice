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
  int cnt;
  TrieNode *child[2];

  TrieNode() {
    cnt = 0;
    child[0] = child[1] = NULL;
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(int num) {
    TrieNode *cur = root;
    cur->cnt++; // represents all inserted no's

    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if (cur->child[bit] == NULL)
        cur->child[bit] = new TrieNode();

      cur = cur->child[bit];
      cur->cnt++;
    }
  }

  int cntXorGreaterEqual(int num, int k) {
    TrieNode *cur = root;
    int ans = 0;

    for (int i = 31; i >= 0; i--) {
      if (cur == NULL)
        break;
      
      // curr pref xor bit
      int xb = (num >> i) & 1;
      int kb = (k >> i) & 1;

      if (kb == 0) {
        // At this bit we need XOR >= 0

        // XOR bit = 1, result becomes > k
        // Valid, cnt entire subtree
        if (cur->child[!xb] != NULL)
          ans += cur->child[!xb]->cnt;

        // Xor bit = 0, result remains equal to k, so far
        // Continue searching this branch 
        cur = cur->child[xb];
      } else {
        // k bit == 1

        // XOR bit must be 1 to remain >= k
        // So we go to opposite bit 
        cur = cur->child[!xb];
      }
    }

    // If we matched every bit, xorr == k
    if (cur != NULL)
      ans += cur->cnt;

    return ans;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;

  vi a(n);
  rv(a);

  ll cnt = 0;

  Trie trie;

  // For empty prefix
  trie.insert(0);

  int pref = 0;

  for (int i = 0; i < n; i++) {
    pref ^= a[i];

    cnt += trie.cntXorGreaterEqual(pref, k);

    trie.insert(pref);
  }

  cout << cnt << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}