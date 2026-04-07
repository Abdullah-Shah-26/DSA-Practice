#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N)
//* SC = O(N)

//! Sliding Window + Monotonic Deque

class Solution {
  public:
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    // cost = max(chargeTimes [L...R]) + (R-L+1) * Sum(RunningCost [L...R])

    int n = chargeTimes.size();
    long long curSum = 0;
    int l = 0, ans = 0;

    deque<int> dq; // Monotonic decreasing dq to maintain maximum

    for(int r = 0; r < n; r++){
      curSum += runningCosts[r];

      // Maintain dq order
      while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r])
        dq.pop_back();

      dq.push_back(r);

      // If Invalid - Shrink Window
      while(!dq.empty() && (long long)chargeTimes[dq.front()] + (r - l + 1) * curSum > budget){

        curSum -= runningCosts[l];

        if(l == dq.front()){ //* Remove from dq if current elem is max
          dq.pop_front();
        }

        l++;
      }

      ans = max(ans, r - l + 1);
    }

    return ans;    
    }
};