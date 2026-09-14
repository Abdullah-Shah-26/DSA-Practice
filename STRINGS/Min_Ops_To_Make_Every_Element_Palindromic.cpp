#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long minOperations(vector<int> &v) {
    static vector<ll> even, odd;
    static bool precompute = false;

    if (!precompute) {
      precompute = true;

      for (ll x = 1; x <= 100000; x++) {
        string s = to_string(x);
        string a = s;

        for (int i = s.size() - 1; i >= 0; i--)
          a += s[i];

        ll p = stoll(a);

        if (p <= 1000000001LL) {
          if (p & 1)
            odd.push_back(p);
          else
            even.push_back(p);
        }

        string b = s;

        for (int i = s.size() - 2; i >= 0; i--)
          b += s[i];

        p = stoll(b);

        if (p <= 1000000001LL) {
          if (p & 1)
            odd.push_back(p);
          else
            even.push_back(p);
        }
      }

      sort(begin(even), end(even));
      sort(begin(odd), end(odd));
    }

    ll ans = 0;

    for (ll x : v) {
      auto &st = (x & 1) ? odd : even;
      auto it = lower_bound(st.begin(), st.end(), x);

      ll ops = LLONG_MAX;

      if (it != st.end())
        ops = min(ops, abs(x - *it));

      if (it != st.begin())
        ops = min(ops, abs(x - *(it - 1)));

      ans += (ops / 2);
    }

    return ans;
  }
};