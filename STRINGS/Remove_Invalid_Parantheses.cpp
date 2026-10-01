#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n, maxL;
  unordered_set<string> st;

  void solve(int i, string &cur, string &s, int open) {
    if (i == n) {
      if (open == 0 && cur.size() == maxL)
        st.insert(cur);

      return;
    }

    // Pruning
    if (cur.size() > maxL)
      return;

    // Take
    int nextOpen = open + (s[i] == '(') - (s[i] == ')');

    if (nextOpen >= 0) {
      cur += s[i];
      solve(i + 1, cur, s, nextOpen);
      cur.pop_back();
    }

    // Skip
    solve(i + 1, cur, s, open);
  }

  void minRemoval(int i, string &cur, string &s, int open) {

    if (i == n) {
      if (open == 0)
        maxL = max(maxL, (int)cur.size());

      return;
    }

    // Take
    int nextOpen = open + (s[i] == '(') - (s[i] == ')');

    if (nextOpen >= 0) {
      cur += s[i];
      minRemoval(i + 1, cur, s, nextOpen);
      cur.pop_back();
    }

    // Skip
    minRemoval(i + 1, cur, s, open);
  }

  vector<string> removeInvalidParentheses(string s) {
    n = s.size();

    int minR = n;
    maxL = 0;

    // Find min removals to make it valid
    // Can actually find max Len of valid one
    string cur = "";

    minRemoval(0, cur, s, 0);

    cur = "";

    solve(0, cur, s, 0);

    vector<string> ans;

    for (auto &w : st)
      ans.push_back(w);

    return ans;
  }
};