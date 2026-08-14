#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int m = a.size() - 1;
    int n = b.size() - 1;

    int sum = 0;
    int carry = 0;

    string ans = "";

    while (m >= 0 || n >= 0) {
      sum = carry;

      if (m >= 0) {
        sum += a[m] - '0';
        m--;
      }

      if (n >= 0) {
        sum += b[n] - '0';
        n--;
      }

      ans.push_back((sum % 2 == 0) ? '0' : '1');

      carry = ((sum > 1) ? 1 : 0);
    }

    if (carry)
      ans.push_back('1');

    reverse(begin(ans), end(ans));

    return ans;
  }
};