#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {

  int l = 0;
  int r = arr.size() - 1;

  while (l < r) {

    int mid = l + (r - l) / 2;

    if (arr[mid] < arr[mid + 1]) {
      // Increasing, so a peak exists on the right.
      l = mid + 1;
    } else {
      // Decreasing (or at a peak), so keep mid.
      r = mid;
    }
  }

  return l;
}