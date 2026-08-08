#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> validSequence(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    vector<int> rhsMatch(n, 0);

    int i = n - 1, j = m - 1;
    int matches = 0;

    while (i >= 0) {
      if (j >= 0 && s1[i] == s2[j]) {
        matches++;
        j--;
      }

      rhsMatch[i] = matches;
      i--;
    }

    vector<int> ans;
    bool can = false; // Can we change this one char

    i = 0, j = 0;
    while (i < n && j < m) {
      if (s1[i] == s2[j]) {
        ans.push_back(i);
        j++;
      } else if (can == false && i + 1 < n && rhsMatch[i + 1] >= m - j - 1) {
        can = true;
        ans.push_back(i);
        j++;
      }
      i++;
    }

    return j == m ? ans : vector<int>();
  }
};