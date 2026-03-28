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
    int toMin(const string &t){
      int h = (t[0] - '0')*10 + (t[1] - '0');
      int m = (t[3] - '0')*10 + (t[4] - '0');
      return h * 60 + m;
    }

    //! TC = O(N Log N)
    //! SC = O(N)
    int findMinDifference(vector<string>& times) {
     int n = times.size();
     int mins[n];
     
     int i = 0;
     for(auto &t : times){
      mins[i] = (toMin(t));
      i++;
     } 

     sort(mins + 0, mins + n);

     int ans = 1440;

     for(int i = 1; i < n; i++){
      ans = min(ans, mins[i] - mins[i-1]);
     }

     return min(ans, 24*60 - mins[n-1] + mins[0]);
    }
};

//! Optimal Approach

class Solution {
public:
    int toMin(const string &t){
      int h = (t[0] - '0')*10 + (t[1] - '0');
      int m = (t[3] - '0')*10 + (t[4] - '0');
      return h * 60 + m;
    }

    //! TC = O(N)
    //! SC = O(1440)
    int findMinDifference(vector<string>& times) {
    
    bool seen[1440] = {false};

    for(auto &i : times){
      int mins = toMin(i);

      // Duplicates then min diff = 0
      if(seen[mins]) return 0; 

      seen[mins] = 1;
    }

    int prev = -1, first = -1;
    int ans = 1e9;

    for(int i = 0; i < 1440; i++){
      if(seen[i]){
        if(prev != -1){
          ans = min(ans, i - prev);
        }
        else{
          first = i;
        }

        prev = i;
      }
    }

    return min(ans, 1440 - prev + first);
    }
};