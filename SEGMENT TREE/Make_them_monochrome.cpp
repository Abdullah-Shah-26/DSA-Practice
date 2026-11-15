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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

F - Make them monochrome /

Time Limit: 2 sec / Memory Limit: 1024 MiB

Score : 500 points
Problem Statement

There is an integer sequence A=(A1​,A2​,…,AN​) of length N.
Process the following Q queries.

Type 1 :

1 i x

Change Ai​ to x.

Type 2 :

2 l r

Suppose that each −1 contained in Al​,Al+1​,…,Ar​ can be replaced with an arbitrary positive integer. Print Yes if Al​,Al+1​,…,Ar​ can all be made equal, and No otherwise.
Constraints

    All input values are integers.
    1≤N,Q≤3×105
    −1≤Ai​≤106
    Ai​=0
    Queries of type 1 satisfy the following constraints:
        1≤i≤N
        −1≤x≤106
        x=0
    Queries of type 2 satisfy the following constraints:
        1≤l≤r≤N

Input

The input is given from Standard Input in the following format, where Queryi​ denotes the i-th query:

N Q
A1​ A2​ … AN​
Query1​
Query2​
⋮
QueryQ​

Output

Each time a query of type 2 is given, print the answer to that query in one line.
Sample Input 1
Copy

8 9
5 -1 3 -1 2 3 4 5
2 3 6
1 5 -1
2 3 6
1 7 5
2 7 8
2 1 8
1 3 5
1 6 -1
2 1 8

Sample Output 1
Copy

No
Yes
Yes
No
Yes

This input contains 9 queries.
Below, we explain the first 3 queries.

    Initially, A=(5,−1,3,−1,2,3,4,5).
    The 1-st query is of type 2, and the subarray in question is (3,−1,2,3). These cannot all be made equal by the operation in the problem statement, so print No.
    The 2-nd query is of type 1, and changes A5​ to −1. As a result, A=(5,−1,3,−1,−1,3,4,5).
    The 3-rd query is of type 2, and the subarray in question is (3,−1,−1,3). These can all be made equal by the operation in the problem statement, so print Yes.



==========================
*/

struct Node {
  int val = 0;
  bool bad = false;
};

Node merge(const Node& a, const Node& b) {
  Node ans;

  ans.bad = a.bad || b.bad || (a.val && b.val && a.val != b.val);
  ans.val = a.val ? a.val : b.val;

  return ans;
}

struct SegTree {
  int n;
  vector<Node> seg;

  SegTree(vi& a) {
    this->n = (int)a.size();
    seg.resize(4 * n);

    build(a, 1, 0, n - 1);
  }

  void build(vi& a, int i, int l, int r) {
    if (l == r) {
      seg[i].val = a[l] == -1 ? 0 : a[l];
      return;
    }

    int mid = (l + r) >> 1;

    build(a, 2 * i, l, mid);
    build(a, 2 * i + 1, mid + 1, r);

    seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
  }

  void update(int i, int l, int r, int pos, int val) {
    if (l == r) {
      seg[i].val = val == -1 ? 0 : val;
      return;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid)
      update(2 * i, l, mid, pos, val);
    else
      update(2 * i + 1, mid + 1, r, pos, val);

    seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
  }

  Node query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return Node();

    if (l >= ql && r <= qr) return seg[i];

    int mid = (l + r) >> 1;

    return merge(query(2 * i, l, mid, ql, qr),
                 query(2 * i + 1, mid + 1, r, ql, qr));
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  vi a(n);
  rv(a);

  SegTree st(a);

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int i, x;
      cin >> i >> x;
      st.update(1, 0, n - 1, i - 1, x);
    } else {
      int l, r;
      cin >> l >> r;

      // Atleast 2 diff +ve int exist
      if (st.query(1, 0, n - 1, l - 1, r - 1).bad)
        NO;
      
      // 
      else
        YES;
    }
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}