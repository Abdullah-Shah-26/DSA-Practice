#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// TC = O((N + M) * sqrt(N) + (M Log M)
// SC = O(N + M + (Max Element for freq vector)) 

int main() {
  int n;
  cin >> n;

  vi a(n);
  for (int &x : a)
    cin >> x;

  int m;
  cin >> m;

  // [l, r, idx]
  vector<array<int, 3>> q(m);

  for (int i = 0; i < m; i++) {
    cin >> q[i][0] >> q[i][1];
    q[i][0]--;
    q[i][1]--;
    q[i][2] = i;
  }

  // Block size
  int B = max(1, (int)sqrt(n));

  sort(begin(q), end(q), [&](auto &a, auto &b) {
    auto [aL, aR, i1] = a;
    auto [bL, bR, i2] = b;

    // Block no's
    int x = aL / B;
    int y = bL / B;

    // Different blocks
    // Query with smaller block no comes first
    if (x != y)
      return x < y;

    // Same block
    // Query with smaller R comes first
    return aR < bR;
  });

  vi freq(*max_element(begin(a), end(a)) + 1);
  vi ans(m);

  int L = 0, R = -1, distinct = 0;

  auto add = [&](int i) {
    if (++freq[a[i]] == 1)
      distinct++;
  };

  auto remove = [&](int i) {
    if (--freq[a[i]] == 0)
      distinct--;
  };

  for (auto [l, r, idx] : q) {

    while (L > l) {
      L--;
      add(L);
    }

    while (R < r) {
      R++;
      add(R);
    }

    while (L < l) {
      remove(L);
      L++;
    }

    while (R > r) {
      remove(R);
      R--;
    }

    ans[idx] = distinct;
  }

  for (auto &x : ans)
    cout << x << " ";

  cout << endl;

  return 0;
}