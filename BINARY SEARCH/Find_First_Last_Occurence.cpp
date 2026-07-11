#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &a, int target) {
    int n = a.size();

    int first = -1;
    int last = -1;

    int l = 0, r = n - 1;

    // 1st Occurence
    while (l <= r) {
      int mid = (l + r) >> 1;

      if (a[mid] >= target) {
        if (a[mid] == target) {
          first = mid;
        }
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    l = 0, r = n - 1;

    // Last Occurence
    while (l <= r) {
      int mid = (l + r) >> 1;

      if (a[mid] <= target) {
        if (a[mid] == target) {
          last = mid;
        }
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    if (first != -1) {
      return {first, last};
    }

    return {-1, -1};
  }
};