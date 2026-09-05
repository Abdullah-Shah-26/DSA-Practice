#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string s = "1";

    for (int step = 1; step < n; step++) {
      string next = "";

      for (int i = 0; i < s.size();) {
        int j = i;

        while (j < s.size() && s[j] == s[i])
          j++;

        int count = (j - i);
        char ch = s[i];

        next += to_string(count);
        next += ch;

        i = j;
      }

      s = next;
    }

    return s;
  }
};