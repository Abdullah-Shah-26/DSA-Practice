#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll LINF = LLONG_MAX;
const int N = 200000;

struct Line {
  ll m;
  ll c;

  Line() {
    m = 0;
    c = LINF;
  }

  Line(ll slope, ll intercept) {
    m = slope;
    c = intercept;
  }

  ll value(ll x) { return (m * x) + c; }
};

Line tree[4 * N];

ll query(int node, int l, int r, int x) {

  // Evaluating line stored in this node
  ll ans = tree[node].value(x);

  if (l == r)
    return ans;

  int mid = (l + r) >> 1;

  if (x <= mid)
    ans = min(ans, query(2 * node, l, mid, x));
  else
    ans = min(ans, query(2 * node + 1, mid + 1, r, x));

  return ans;
}

void printLine(Line line) {
  cout << "y = " << line.m << "x + " << line.c << endl;
}

// Node stores which line is best at midpt of its interval

// For interval [l, r], this node stores the line
// that is best at x = (l + r) / 2.

void insert(Line newLine, int node, int l, int r) {

  // printing
  cout << "Node [" << l << ", " << r << "]\n";

  cout << "Current: ";
  printLine(tree[node]);

  cout << "New: ";
  printLine(newLine);

  int mid = (l + r) >> 1;

  bool leftBetter = newLine.value(l) < tree[node].value(l);
  bool midBetter = newLine.value(mid) < tree[node].value(mid);

  if (midBetter)
    swap(tree[node], newLine);

  if (l == r)
    return;

  if (leftBetter != midBetter) // Different ordering
    insert(newLine, 2 * node, l, mid);
  else
    insert(newLine, 2 * node + 1, mid + 1, r);
}

const int xmin = 0;
const int xmax = 15;

int main() {
  insert(Line(1, 0), 1, xmin, xmax);   // y = x
  insert(Line(0, 10), 1, xmin, xmax);  // y = 10
  insert(Line(-1, 20), 1, xmin, xmax); // y = -x + 20

  for (int x = xmin; x <= xmax; x++) {
    cout << "x = " << x << " minY = " << query(1, xmin, xmax, x) << endl;
  }

  return 0;
}