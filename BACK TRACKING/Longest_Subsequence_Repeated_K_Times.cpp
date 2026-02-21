#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
using ld = long double;

using pi = pair<int, int>;
using pll = pair<ll, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

static const auto fastio = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// -------- lll (__int128) I/O --------
lll readlll()
{
  string s;
  cin >> s;
  lll x = 0;
  int i = 0;
  bool neg = false;
  if (!s.empty() && s[0] == '-')
    neg = true, i = 1;
  for (; i < (int)s.size(); i++)
    x = x * 10 + (s[i] - '0');
  return neg ? -x : x;
}
void printlll(lll x)
{
  if (x == 0)
  {
    cout << 0;
    return;
  }
  if (x < 0)
    cout << '-', x = -x;
  string s;
  while (x)
  {
    s.push_back(char('0' + (int)(x % 10)));
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
}
// -----------------------------------

// -------- Fast vector/matrix input ---
#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
// -----------------------------------

void solve()
{
  int n;
  cin >> n;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

/// TC = O(N . M^L)
// SC = (M^L)

class Solution
{
public:
  bool canRepeatK(string &s, string &next, int &k)
  {
    int i = 0, j = 0;
    int cnt = 0;
    while (i < s.size())
    {
      if (s[i] == next[j])
      {
        j++;
        if (j == next.size())
        {
          j = 0;
          cnt++;
        }
      }
      i++;
    }
    return cnt >= k;
  }
  string longestSubsequenceRepeatedK(string s, int k)
  {
    int n = s.size();
    int freq[26] = {};
    for (int i = 0; i < n; i++)
    {
      freq[s[i] - 'a']++;
    } // BFS string
    string curr = "";
    queue<string> q;
    q.push(curr);
    string res = "";
    while (!q.empty())
    {
      curr = q.front();
      q.pop();
      string next = curr; // Try to append each char & check if its present in subseqeunce >= k times
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        if (freq[ch - 'a'] < k)
        {
          continue;
        }
        next.push_back(ch);
        if (canRepeatK(s, next, k))
        {
          res = next;
          q.push(next);
        }
        next.pop_back();
      }
    }
    return res;
  }
};