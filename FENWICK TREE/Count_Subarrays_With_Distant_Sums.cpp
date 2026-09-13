#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Fenwick {
public:
  int n;
  vector<ll> bit;

  Fenwick(int n) {
    this->n = n;
    bit.resize(n + 1);
  }

  void update(int i, ll val) {
    while (i <= n) {
      bit[i] += val;
      i += (i & -i);
    }
  }

  ll query(int i) {
    ll sum = 0;

    while (i > 0) {
      sum += bit[i];
      i -= (i & -i);
    }

    return sum;
  }
};

class Solution {
public:
  long long distantSubarrays(vector<int> &nums, int goal, int k) {
    int n = nums.size();

    if (k == 0)
      return 1LL * n * (n + 1) / 2;

    vector<ll> pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + nums[i - 1];

    vector<ll> vals = pref;
    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals), end(vals)), end(vals));

    int m = vals.size();

    Fenwick ft(m);

    ll cnt = 0;

    for (int i = 0; i <= n; i++) {
      ll cur = pref[i];

      // No of prev prefix sums <= X
      ll X = cur - goal - k;
      int id = upper_bound(begin(vals), end(vals), X) - begin(vals);
      cnt += ft.query(id);

      // No of prev prefix sums >= Y
      ll Y = cur - goal + k;
      id = lower_bound(begin(vals), end(vals), Y) - begin(vals);
      cnt += ft.query(m) - ft.query(id);

      id = lower_bound(begin(vals), end(vals), pref[i]) - vals.begin() + 1;

      ft.update(id, 1); // Increase freq by 1
    }

    return cnt;
  }
};