#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log N)
//! SC = O(N)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
    // Min Groups 
    // Max OverLaps at any point

    map<int,int> m;

    for(auto &i : intervals){
      int st = i[0];
      int end = i[1];

      m[st]++;
      m[end + 1]--;
    }
    int cumSum = 0;
    int maxOverLaps = 1;
    for(auto &it : m){
      cumSum += it.second;

      if(cumSum > maxOverLaps){
        maxOverLaps = cumSum;
      }
    }

    return maxOverLaps;
    }
};

//! Differance Array Technique

//! TC = O(N + maxRange)
//! SC = O(maxRange)

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
    int maxi = 0;

    for(auto &i : intervals){
      maxi = max(maxi, i[1]);
    }    

    vector<int> diff(maxi + 2, 0);

    for(auto &i : intervals){
      int st = i[0];
      int end = i[1];

      diff[st]++;
      diff[end + 1]--;
    }

    int maxOverLaps = 0;
    int cumSum = 0;

    for(int &d : diff){
      cumSum += d;
      maxOverLaps = max(cumSum, maxOverLaps);
    }

    return maxOverLaps;
    }
};