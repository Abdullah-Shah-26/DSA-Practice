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
    int maximumPopulation(vector<vector<int>>& logs) {
    // Difference Arr Technique

    // TC = O(N + Q)
    // SC = O(1)
    vector<int> diff(2051, 0);

    for(auto &log : logs){
      int birth = log[0]; // st = log[0] 
      int death = log[1]; // end = log[1] - 1

      diff[birth]++;
      diff[death]--; // diff[end + 1] -= 1
    }    

    int maxPop = 0;
    int curPop = 0;
    int minYear = 2050;

    for(int year = 1950; year < 2051; year++){
      curPop += diff[year];

      if(curPop > maxPop){
        minYear = year;
        maxPop = curPop;
      }
    }
    return minYear;
    }
};

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
    // Line Sweep 

    vector<pair<int,int>> events;
    // TC = O(NLogN + N)
    // SC = O(N)
    for(auto &log : logs){
      events.emplace_back(log[0], +1);
      events.emplace_back(log[1], -1);
    }    

    sort(begin(events), end(events));

    int curPop = 0;
    int maxPop = 0;
    int minYear = 2050;

    for(auto &e : events){
      curPop += e.second;

      if(curPop > maxPop){
        minYear = e.first;
        maxPop = curPop;
      }
    }

    return minYear;
    }
};