#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Approach 1 - LineSweep
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

//! Approach 2 - Sorting + Merge Intervals
//! TC = O(N Log N)
//! SC = O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
         int n = arr.size();
         vector<vector<int>>ans;
         sort(arr.begin(), arr.end());
         int curSt = arr[0][0];
         int curEnd = arr[0][1];

         for(int i = 1; i < n; i++){
          int nextSt = arr[i][0];
          int nextEnd = arr[i][1];

          if(nextSt <= curEnd){
            // OverLap
            curEnd = max(curEnd, nextEnd);
          }
          else{
            // No Overlap
            ans.push_back({curSt, curEnd});
            curSt = nextSt;
            curEnd = nextEnd;
          }
         }

    // If all intervals merged, then else didnt get executed
    ans.push_back({curSt, curEnd});   

    return ans;
    }
}; 
