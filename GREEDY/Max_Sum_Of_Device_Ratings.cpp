#include <bits/stdc++.h>
using namespace std;

// TC = O(N * M)

using ll = long long;
const int INF = 1e9;

class Solution {
public:
  long long maxRatings(vector<vector<int>>& units) {
  int n = units.size();
  int m = units[0].size();
  ll ans = 0;

  // Edge Case : 
  if(m == 1){ 
    // Each row has only 1 element
    // No need to remove minElem else rating of that device becomes 0 
    for(auto vec : units) 
      ans += vec[0];

    return ans;
  }

  int minFirst = INF, minSecond = INF;
  ll sum = 0; // Sum of all second mininum's

  for(int i = 0; i < n; i++){
    int mini1 = INF; // First small
    int mini2 = INF; // Second small
    
    for(int j = 0; j < m; j++){
      int x = units[i][j];

      if(x < mini1){
        mini2 = mini1;
        mini1 = x;
      } 
      else if(x < mini2){
        mini2 = x;
      }
    }

    minFirst = min(minFirst, mini1);
    minSecond = min(minSecond, mini2);
    sum += mini2;
  }

  return sum - minSecond + minFirst; 
  }
};