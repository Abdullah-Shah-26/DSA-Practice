#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution
{
public:
  int calculate(string s)
  {
    long num = 0, last = 0, ans = 0;
    char op = '+';

    for (int i = 0; i <= s.size(); i++)
    {

      if (i < s.size() && s[i] == ' ')
      {
        continue;
      }

      if (i < s.size() && isdigit(s[i]))
      {
        num = (num * 10) + (s[i] - '0');
        continue;
      }

      if (op == '+')
      {
        ans += num;
        last = num;
      }
      else if (op == '-')
      {
        ans -= num;
        last = -num;
      }
      else if (op == '*')
      {
        ans = ans - last + last * num;
        last = last * num;
      }
      else if (op == '/')
      {
        ans = ans - last + last / num;
        last = last / num;
      }

      if (i < s.size())
      {
        op = s[i];
      }

      num = 0;
    }
    return ans;
  }
};