#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool canAllocate(const vector<int> &books, int students, int maxPages) {
    int usedStudents = 1;
    int pages = 0;

    for (int bookPages : books) {
      if (bookPages > maxPages)
        return false;

      if (pages + bookPages <= maxPages) {
        pages += bookPages;
      } else {
        usedStudents++;
        pages = bookPages;
      }
    }

    return usedStudents <= students;
  }

public:
  int books(vector<int> &arr, int m) {
    int n = static_cast<int>(arr.size());
    if (m > n)
      return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int answer = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (canAllocate(arr, m, mid)) {
        answer = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return answer;
  }
};
