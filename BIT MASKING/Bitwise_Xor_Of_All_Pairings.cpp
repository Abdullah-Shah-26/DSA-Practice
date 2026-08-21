#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int xorAllNums(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();

    int xora = 0;
    int xorb = 0;

    for (int x : a)
      xora ^= x;

    for (int y : b)
      xorb ^= y;

    int ans = 0;

    for (int i = 0; i < m; i++)
      ans ^= xora;

    for (int i = 0; i < n; i++)
      ans ^= xorb;

    return ans;
  }
};