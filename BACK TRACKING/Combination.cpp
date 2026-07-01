#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void solve(int idx, vector<int> temp, vector<int> &arr, int tar,
             vector<vector<int>> &ans, int n) {
    if (idx == n) {
      if (tar == 0) {
        ans.push_back(temp);
        return;
      }
    }
    if (tar < 0 || idx >= n)
      return;

    temp.push_back(arr[idx]);
    solve(idx, temp, arr, tar - arr[idx], ans, n);
    temp.pop_back();
    solve(idx + 1, temp, arr, tar, ans, n);
  }

  vector<vector<int>> combinationSum(vector<int> &arr, int tar) {
    vector<vector<int>> ans;
    vector<int> temp;
    int n = arr.size();
    solve(0, temp, arr, tar, ans, n);
    return ans;
  }
};