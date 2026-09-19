#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumCostSubstring(string s, string chars, vector<int> &vals) {
    unordered_map<char, int> mp;

    for (int i = 0; i < chars.size(); i++) {
      mp[chars[i]] = vals[i];
    }

    vector<int> arr;

    for (int i = 0; i < s.size(); i++) {
      if (mp.count(s[i]))
        arr.push_back(mp[s[i]]);
      else
        arr.push_back(s[i] - 'a' + 1);
    }

    int curSum = 0, maxSum = INT_MIN;

    for (int val : arr) {
      curSum += val;

      if (curSum < 0)
        curSum = 0;

      maxSum = max(maxSum, curSum);
    }

    return maxSum;
  }
};