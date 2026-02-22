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

//! Line Sweep
// TC = O(NlogN)
// SC = O(N)

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    map<int,long long> events;

    for(auto &s : segments){
      int st = s[0];
      int end = s[1];
      long long color = s[2];

      events[st] += color;
      events[end] -= color;
    }

    vector<vector<long long>> res;
    auto it = events.begin();
    
    long long sum = it->second;
    long long start = it->first;
    it++;

    while(it != events.end()){
      if(sum > 0){
        res.push_back({start,it->first,sum});
      }
      start = it->first;
      sum += it->second;
      it++;
    }
    return res;
    }
};