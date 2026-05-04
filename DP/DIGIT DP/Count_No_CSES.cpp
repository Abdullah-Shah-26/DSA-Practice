#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// 10 ^ 18 -- 19 digits -- Keep 20 in dp
// lz - 0/1
// tight - 0/1
// prev - // 0->9 , we are also using 10 as no past prev -- so overall 11

ll dp[2][11][20][2];

ll f(string &s, bool tight, ll prev, ll idx, ll lz)
{

  if (idx == (int)s.size())
  {
    return 1; // valid No
  }

  if (dp[tight][prev][idx][lz] != -1)
  {
    return dp[tight][prev][idx][lz];
  }

  ll lowerBound = 0;
  ll upperBound = (tight == true) ? s[idx] - '0' : 9;

  ll res = 0;
  for (ll d = lowerBound; d <= upperBound; d++)
  {

    // Valid case
    bool newTight = tight && (d == upperBound);
    bool newLz = lz && (d == 0);
    ll newPrev = newLz ? 10 : d;

    // Invalid Case
    if (!newLz && d == prev)
    {
      continue;
    }

    res += f(s, newTight, newPrev, idx + 1, newLz);
  }
  return dp[tight][prev][idx][lz] = res;
}

ll solve(ll a, ll b)
{

  string r = to_string(b);

  // i --- current idx
  // tight --- (1 - bounded) (0 - unbounded)
  // prev ---- (10 - Its like -1 , No past value, since we are memoizing so not using -1 )
  // lz --- (leading zeros - 0 - false - 1 - true)
  
  memset(dp, -1, sizeof(dp));
  ll resR = f(r, 1, 10, 0, 1);

  if (a == 0)
  {
    return resR;
  }
  string l = to_string(a - 1);

  memset(dp, -1, sizeof(dp));
  ll resL = f(l, 1, 10, 0, 1);

  return resR - resL;
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
}