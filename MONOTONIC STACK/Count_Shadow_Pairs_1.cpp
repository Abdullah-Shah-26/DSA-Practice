#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long shadowPairs(vector<int> &nums) {
    ll cnt = 0;

    vector<int> st;

    for (int x : nums) {

      while (!st.empty() && st.back() > x)
        st.pop_back();

      // Counts elements that are strictly < x
      cnt += lower_bound(begin(st), end(st), x) - begin(st);

      st.push_back(x);
    }

    return cnt;
  }
};