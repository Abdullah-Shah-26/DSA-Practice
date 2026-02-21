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

class MyCalendarTwo {
public:
    map<int,int> events;

    MyCalendarTwo() {
        
    }
    
    bool book(int stTime, int endTime) {
      // TC = O(N * (LogN + N))
      //       Booking fun called * (map update + traversal)

      // SC =  O(N)
      events[stTime] += 1;
      events[endTime] -= 1;

      int cnt = 0;
      for(auto &it : events){ 
          cnt += it.second;

          if(cnt > 2){
            events[stTime] -= 1;
            events[endTime] += 1;

            return false;
          }
      }
    return true;
    }
};
