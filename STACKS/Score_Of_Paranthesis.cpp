#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int scoreOfParentheses(string s) {
    int cnt = 0;

    stack<int> st;

    for (char c : s) {
      int val = 0;

      if (c == '(')
        st.push(0);

      else {
        while (!st.empty() && st.top() != 0) {
          val += st.top();
          st.pop();
        }

        val = max(1, 2 * val);
        st.pop();
        st.push(val);
      }
    }

    while (!st.empty()) {
      cnt += st.top();
      st.pop();
    }

    return cnt;
  }
};