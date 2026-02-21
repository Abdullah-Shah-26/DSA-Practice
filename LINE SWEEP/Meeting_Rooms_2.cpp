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
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
    // TC = O(N Log N)
    // SC = O(N)
    
    map<int,int>m; // Event , delta
    int n = start.size();
    for(int i = 0; i < n; i++){
        m[start[i]]++;
        m[end[i]]--;
    }
    // Min rooms - means Max Overlaps
    int overLaps = 0;
    int maxOverLap = 0;
    for(auto &e : m){
        overLaps += e.second;
        
        if(overLaps > maxOverLap){
            maxOverLap = overLaps;
        }
    }
    return maxOverLap;
    }
};
