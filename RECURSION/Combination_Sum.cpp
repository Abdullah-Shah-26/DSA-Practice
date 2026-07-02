#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  set<vector<int>> st;

  void dfs(vector<int> &a, int i, int tar, vector<int> &cur,
           vector<vector<int>> &ans) {

    if (tar == 0) {
      if (!st.count(cur)) {
        st.insert(cur);
        ans.push_back(cur);
      }
      return;
    }

    if (i == a.size() || tar < 0)
      return;

    // Take once
    cur.push_back(a[i]);
    dfs(a, i + 1, tar - a[i], cur, ans);

    // Take again
    dfs(a, i, tar - a[i], cur, ans);
    cur.pop_back();

    // Skip
    dfs(a, i + 1, tar, cur, ans);
  }

  vector<vector<int>> combinationSum(vector<int> &a, int tar) {
    vector<vector<int>> ans;
    vector<int> cur;

    dfs(a, 0, tar, cur, ans);
    return ans;
  }
};