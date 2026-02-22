#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

const int MOD = 1e9 + 7;
class Solution
{
public:
  int maxSumRangeQuery(vector<int> &a, vector<vector<int>> &req)
  {
    // Differance Array Technique
    // TC = O(N Log N)
    // SC = O(N)
    int n = a.size();
    vector<unsigned> events(n, 0);

    for (auto &r : req)
    {
      int st = r[0];
      int end = r[1];

      events[st] += 1;
      if (end + 1 < n)
        events[end + 1] -= 1;
    }

    // cumulative sum
    for (int i = 1; i < n; i++)
    {
      events[i] = (events[i] + events[i - 1]) % MOD;
    }

    unsigned res = 0; // max sum

    sort(begin(a), end(a), greater<int>());
    sort(begin(events), end(events), greater<int>());

    for (int i = 0; i < n; i++)
    {
      res = (res + (events[i] * a[i]) % MOD) % MOD;
    }
    return res % MOD;
  }
};