#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mini = 1e9;
  int n;
  void solve(int idx, vector<int> &children, vector<int> &cookies, int k) {
    if (idx >= n) {
      mini = min(mini, *max_element(begin(children), end(children)));
      return;
    }
    int cookie = cookies[idx];
    for (int i = 0; i < k; i++) {
      children[i] += cookie;
      solve(idx + 1, children, cookies, k);
      children[i] -= cookie;

      if (children[i] == 0)
        break;
    }
  }

  int distributeCookies(vector<int> &cookies, int k) {
    vector<int> children(k);
    n = cookies.size();
    solve(0, children, cookies, k);

    return mini;
  }
};