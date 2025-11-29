#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size())
    {
      cout << "NO" << endl;
      continue;
    }
    unordered_map<char, int> m;
    for (char c : s)
      m[c]++;

    bool ok = true;
    for (char c : t)
    {
      if (m.find(c) == m.end() || m[c] == 0)
      {
        ok = false;
        break;
      }
      m[c]--; 
    }

    if (ok)
    {
      for (auto &p : m)
      {
        if (p.second != 0)
          ok = false;
      }
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}