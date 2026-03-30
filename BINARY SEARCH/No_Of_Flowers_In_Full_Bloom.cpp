#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log N + M Log N)
//! SC = O(2 * N)

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<int> birth, death;

    for(auto &f : flowers){ // O(N)
      int s = f[0];
      int e = f[1];
      birth.push_back(s);
      death.push_back(e);
    }

    // O(N Log N)
    sort(begin(birth), end(birth));
    sort(begin(death), end(death));

    vector<int> result;

    for(auto &p : people){ // O(M * Log N)
      auto x = upper_bound(begin(birth),end(birth),p) - begin(birth); 
      auto y = lower_bound(begin(death),end(death),p) - begin(death);

      result.push_back(x - y);
    }

    return result;
    }
};