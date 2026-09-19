#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int clumsy(int n) {
    stack<int> st;
    st.push(n);
    n--;

    // 0:*, 1:/, 2:+, 3:-
    int i = 0;

    while (n > 0) {

      if (i == 0) {
        int x = st.top();
        st.pop();
        st.push(x * n);
      } else if (i == 1) {
        int x = st.top();
        st.pop();
        st.push(x / n);
      } else if (i == 2)
        st.push(n);
      else
        st.push(-n);

      i = (i + 1) % 4;
      n--;
    }

    int ans = 0;

    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }

    return ans;
  }
};