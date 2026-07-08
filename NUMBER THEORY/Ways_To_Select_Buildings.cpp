#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long numberOfWays(string s) {
    int n = s.size();

    vector<int> pref0(n + 1);
    vector<int> pref1(n + 1);

    for (int i = 0; i < n; i++) {
      pref0[i + 1] = pref0[i] + (s[i] == '0');
      pref1[i + 1] = pref1[i] + (s[i] == '1');
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {

      int left0 = pref0[i];
      int left1 = pref1[i];

      // [L...R] - [i+1 ...... n-1]
      // pref[R + 1] - pref[L] = pref[(n-1)+1] - pref[i+1]

      int right0 = pref0[n] - pref0[i + 1];
      int right1 = pref1[n] - pref1[i + 1];

      if (s[i] == '0')
        ans += 1LL * left1 * right1; // 101
      else
        ans += 1LL * left0 * right0; // 010
    }

    return ans;
  }
};