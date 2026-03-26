#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
    //! TC = O(NlogN)
    //! SC = O(N)
    
    map<int,int>diff;

    for(auto &m : meetings){
      int st =  m[0];
      int end = m[1];

      diff[st]++;
      diff[end+1]--;
    } 

    int prev = 1;
    int cumSum = 0;
    int freeDays = 0;

    for(auto &[day, val] : diff){
      if(prev < day && cumSum == 0){
        freeDays += (day - prev);
      }

      cumSum += val;
      prev = day;
    }

    if(prev <= days && cumSum == 0){
      freeDays += (days - prev + 1);
    }

    return freeDays;
    }
};