#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPaint(vector<int> &arr, int k, int maxTime) {

    int painters = 1;
    int currTime = 0;

    for (int board : arr) {

      if (currTime + board <= maxTime) {
        currTime += board;
      } else {
        painters++;
        currTime = board;
      }
    }

    return painters <= k;
  }

  int minTime(vector<int> &arr, int k) {

    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);

    int ans = r;

    while (l <= r) {

      int mid = l + (r - l) / 2;

      if (canPaint(arr, k, mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};