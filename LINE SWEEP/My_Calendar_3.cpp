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

class MyCalendarThree
{
public:
  // events,delta
  map<int, int> events;
  // TC = O(N * (logN + N))
  // SC = O(N)
  MyCalendarThree()
  {
  }

  int book(int s, int e)
  {
    events[s] += 1;
    events[e] -= 1;
    int maxInt = 0; // max Intersection
    int cnt = 0;    // count Intersection

    for (auto &e : events)
    {
      cnt += e.second;
      maxInt = max(maxInt, cnt);
    }
    return maxInt;
  }
};
