#include <bits/stdc++.h>
using namespace std;

// TC = O(NlogN)
// Patience Sorting - Breaks Lexicographical Ordering of Indices

class Solution {
public:
  int lengthOfLIS(vector<int> &arr) {
    int n = arr.size();

    vector<int> sorted;

    for (int i = 0; i < n; i++) {
      auto it = lower_bound(sorted.begin(), sorted.end(), arr[i]);

      if (it == sorted.end())
        sorted.push_back(arr[i]);
      else
        *it = arr[i];
    }

    return sorted.size();
  }
};