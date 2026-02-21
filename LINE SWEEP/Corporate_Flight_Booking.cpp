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

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    // Line Sweep Algo
    // TC = O(M + N)
    // SC = O(N)
    vector<int>arr(n + 2, 0);
    int m = bookings.size()
    for(int i = 0; i < m; i++){
      int st = bookings[i][0];
      int end = bookings[i][1];
      int seats = bookings[i][2];

      arr[st] += seats;
      arr[end + 1] -= seats;
    }
    vector<int>ans(n);

    int cumSum = 0;
    for(int i = 1; i <= n; i++){
      cumSum += arr[i];
      ans[i-1] = cumSum;
    }
    return ans;
    }
};