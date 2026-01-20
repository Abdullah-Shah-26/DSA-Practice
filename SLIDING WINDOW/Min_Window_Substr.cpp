#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

class Solution
{
public:
  string minWindow(string &s, string &t)
  {
    // Code here
    int m[26] = {0};
    int n = s.size();
    int mm = t.size();
    int l = 0, r = 0, minL = 1e9, stIdx = -1, cnt = 0;

    for (int i = 0; i < mm; i++)
    {
      m[t[i] - 'a']++;
    }
    while (r < n)
    {
      if (m[s[r] - 'a'] > 0)
        cnt++;
      m[s[r] - 'a']--;
      while (cnt == mm)
      {
        if (r - l + 1 < minL)
        {
          minL = r - l + 1;
          stIdx = l;
        }
        m[s[l] - 'a']++;
        if (m[s[l] - 'a'] > 0)
          cnt--;
        l++;
      }
      r++;
    }
    return stIdx == -1 ? "" : s.substr(stIdx, minL);
  }
};
