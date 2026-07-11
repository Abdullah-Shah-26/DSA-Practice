#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countZeroes(vector<int> &arr) {

    int l = 0;
    int r = arr.size() - 1;

    int first = -1;

    while (l <= r) {

      int mid = l + (r - l) / 2;

      if (arr[mid] == 0) {
        first = mid; // Possible first 0
        r = mid - 1; // Look further left
      } else {
        l = mid + 1; // Skip all 1s
      }
    }

    if (first == -1)
      return 0;

    return arr.size() - first;
  }
};