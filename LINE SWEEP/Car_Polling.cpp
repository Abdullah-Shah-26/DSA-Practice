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
//! Line Sweep
// TC = O(N*LogN + N)
// SC = O(N)
class Solution
{
public:
  bool carPooling(vector<vector<int>> &trips, int capacity)
  {
    map<int, int> events;
    for (int i = 0; i < trips.size(); i++)
    {
      int NofPassengers = trips[i][0];
      int st = trips[i][1];
      int end = trips[i][2];

      events[st] += NofPassengers;
      events[end] -= NofPassengers;
    }
    int cnt = 0;
    for (auto &it : events)
    {
      cnt += it.second;

      if (cnt > capacity)
      {
        return false;
      }
    }
    return true;
  }
};

//! Difference Array Technique
class Solution
{
public:
  bool carPooling(vector<vector<int>> &trips, int capacity)
  {
    // TC = O(N)
    // SC = O(N)
    vector<int> arr(1001, 0);
    for (int i = 0; i < trips.size(); i++)
    {
      int NofPass = trips[i][0];
      int st = trips[i][1];
      int end = trips[i][2];

      arr[st] += NofPass;
      arr[end] -= NofPass;
    }

    int cumSum = 0;

    for (int i = 0; i <= 1000; i++)
    {
      cumSum += arr[i];

      if (cumSum > capacity)
      {
        return false;
      }
    }
    return true;
  }
};