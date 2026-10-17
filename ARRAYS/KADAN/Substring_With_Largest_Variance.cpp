#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestVariance(string s) {
    int ans = 0;

    unordered_set<char> unique(begin(s), end(s));

    for (char first : unique) {
      for (char second : unique) {

        int cnt1 = 0, cnt2 = 0;
        bool past2 = false; // Saw the second char, before reset

        for (char ch : s) {
          if (ch == first)
            cnt1++;

          if (ch == second)
            cnt2++;

          // Like kadans
          if (cnt2 > cnt1) {
            cnt1 = 0;
            cnt2 = 0;
            past2 = true;
          } else if (cnt2 > 0)
            ans = max(ans, cnt1 - cnt2);
          else {
            if (past2 == true)
              ans = max(ans, cnt1 - 1);
          }
        }
      }
    }
    return ans;
  }
};