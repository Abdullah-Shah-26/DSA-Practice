#include <bits/stdc++.h>
using namespace std;

// TC = O(Log(1e18) * Log(min(r1,r2)))

using ll = long long;
class Solution {
  public:

    // d = [3, 1]
    // r = [2, 3]

    // 2 4 6 8 , drone1 can work on 1,3,5,7
    // 3 6 9 12 , drone2 can work on 1,2,4,5

    // suppose t = 5
    // useful time for drone1 = t - t/2 = 5 - 5/2 = 3
    //                 drone2 = t - t/3 = 5 - 5/3 = 4

    // d1 = 3 <= useful time points(3) -> drone1 can complete task
    // d2 = 1 <= (4) drone2 can complete task

    // d1 + d2 = 3 + 1 = 4 <= (t - t/lcm(r1,r2))

    bool possible(ll t, vector<int> &d, vector<int> &r){
      ll w1 = t - t/r[0]; // drone 1 can work during these time points
      ll w2 = t - t/r[1]; // drone 2 

      if(d[0] > w1 || d[1] > w2) return false;

      return (d[0] + d[1] <= (t - t/lcm(r[0], r[1])));
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
    ll low = 0, high = 1e18;
    ll ans = high;

    while(low <= high){
      ll mid = (low + high) >> 1;

      if(possible(mid, d, r)){
        ans = mid;
        high = mid-1;
      }
      else{
        low = mid+1;
      }
    }    

    return ans;
    }
};