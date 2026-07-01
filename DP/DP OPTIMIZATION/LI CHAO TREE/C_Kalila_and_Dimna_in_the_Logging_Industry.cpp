#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll LINF = (1LL << 62);

// Dynamic Lichao Tree

struct Line {
  ll m, c;

  Line(ll _m = 0, ll _c = LINF) : m(_m), c(_c) {}

  ll get(ll x) const { return m * x + c; }
};

struct Node {
  Line line;
  Node *left, *right;

  Node() : line(), left(nullptr), right(nullptr) {}
};

struct LiChao {
  Node *root;
  ll L, R;

  LiChao(ll l, ll r) {
    L = l;
    R = r;
    root = new Node();
  }

  void addLine(Line newLine) { insert(root, L, R, newLine); }

  ll query(ll x) { return query(root, L, R, x); }

private:
  void insert(Node *node, ll l, ll r, Line newLine) {
    ll mid = (l + r) >> 1;

    bool left = newLine.get(l) < node->line.get(l);
    bool middle = newLine.get(mid) < node->line.get(mid);

    if (middle)
      swap(node->line, newLine);

    if (l == r)
      return;

    if (left != middle) {
      if (!node->left)
        node->left = new Node();
      insert(node->left, l, mid, newLine);
    } else {
      if (!node->right)
        node->right = new Node();
      insert(node->right, mid + 1, r, newLine);
    }
  }

  ll query(Node *node, ll l, ll r, ll x) {
    if (!node)
      return LINF;

    ll ans = node->line.get(x);

    if (l == r)
      return ans;

    ll mid = (l + r) >> 1;

    if (x <= mid)
      return min(ans, query(node->left, l, mid, x));
    else
      return min(ans, query(node->right, mid + 1, r, x));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> a(n + 1), b(n + 1), dp(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
    cin >> b[i];

  LiChao lichao(1, 1000000000LL);

  dp[1] = 0;
  lichao.addLine(Line(b[1], dp[1]));

  for (int i = 2; i <= n; i++) {
    dp[i] = lichao.query(a[i]);
    lichao.addLine(Line(b[i], dp[i]));
  }

  cout << dp[n] << '\n';
}