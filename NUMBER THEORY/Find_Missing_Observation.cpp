#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int m = rolls.size();

    // Total Obsv = m + n
    // Mean = Sum of Obsv / Total Obsv
    // Sum of All Obsv (Including Mising) = Mean * Total Obsv
    // Missing = n

    int sum = accumulate(begin(rolls), end(rolls), 0);
    int remSum = (mean * (n + m)) - sum;

    // A dice has 6 sides
    // If we cannot make the remSum by getting all 6 all n times
    // Then we can never make that sum

    // A dice can have 1, 2, 3, 4, 5, 6
    // The least we can have is 1
    // So Least sum = n * 1
    // If remSum < (n * 1)
    // Its impossible

    if (n * 6 < remSum || remSum < n)
      return {};

    int distribute = remSum / n;
    int mod = remSum % n;

    vector<int> ans(n, distribute);

    for (int i = 0; i < mod; i++)
      ans[i]++;

    return ans;
  }
};