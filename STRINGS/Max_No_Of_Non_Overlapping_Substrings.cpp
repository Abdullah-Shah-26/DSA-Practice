#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();

    // first[c] = first occurance of c
    // last[c] = last occurance of c

    vector<int> first(26, n);
    vector<int> last(26, -1);

    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      first[c] = min(first[c], i);
      last[c] = i;
    }

    vector<pair<int, int>> intervals;

    // Build smallest valid interval for every char
    for (int c = 0; c < 26; c++) {
      if (last[c] == -1)
        continue;

      int l = first[c];
      int r = last[c];
      bool valid = true;

      // Expanding r while necessary
      for (int i = l; i <= r; i++) {
        int x = s[i] - 'a';

        // x has an occurence before l
        // Therefor no valid substring starting at l can exist
        if (first[x] < l) {
          valid = false;
          break;
        }

        r = max(r, last[x]);
      }

      if (valid)
        intervals.push_back({l, r});
    }

    // Smaller valid intervals first
    sort(begin(intervals), end(intervals), [](auto &a, auto &b) {
      return (a.second - a.first) < (b.second - b.first);
    });

    vector<string> ans;
    vector<pair<int, int>> chosen;

    for (auto [l, r] : intervals) {
      bool canTake = true;

      for (auto [x, y] : chosen) {
        // [l,r] and [x,y] overlap then we can't take
        if (max(l, x) <= min(r, y)) {
          canTake = false;
          break;
        }
      }

      if (canTake) {
        chosen.push_back({l, r});
        ans.push_back(s.substr(l, r - l + 1));
      }
    }

    return ans;
  }
};