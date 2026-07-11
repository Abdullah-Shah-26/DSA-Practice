#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstOcc(vector<int> &arr, int target) {

    int l = 0, r = arr.size() - 1;
    int ans = -1;

    while (l <= r) {

      int mid = l + (r - l) / 2;

      if (arr[mid] == target) {
        ans = mid;
        r = mid - 1;
      } else if (arr[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }

  int lastOcc(vector<int> &arr, int target) {

    int l = 0, r = arr.size() - 1;
    int ans = -1;

    while (l <= r) {

      int mid = l + (r - l) / 2;

      if (arr[mid] == target) {
        ans = mid;
        l = mid + 1;
      } else if (arr[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }

  int countFreq(vector<int> &arr, int target) {

    int first = firstOcc(arr, target);

    if (first == -1)
      return 0;

    int last = lastOcc(arr, target);

    return last - first + 1;
  }
};