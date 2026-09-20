#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(int x, int y) {
    string s1 = to_string(x);
    string s2 = to_string(y);

    int n = s1.size();
    int m = s2.size();

    int maxL = max(n, m);

    // Adding 0 to front does change the actual value of number

    while (n != maxL) {
      s1 = "0" + s1;
      n++;
    }

    while (m != maxL) {
      s2 = "0" + s2;
      m++;
    }

    int diff = 0;
    vector<int> f1(10, 0), f2(10, 0);

    for (int i = 0; i < n; i++) {
      diff += (s1[i] != s2[i]);
      f1[s1[i] - '0']++;
      f2[s2[i] - '0']++;
    }

    // No's must have same digits but at different positions
    return diff <= 2 && f1 == f2;
  }

  int countPairs(vector<int> &nums) {
    int n = nums.size();

    int cnt = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        cnt += f(nums[i], nums[j]);
      }
    }

    return cnt;
  }
};