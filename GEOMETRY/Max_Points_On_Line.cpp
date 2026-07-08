#include <bits/stdc++.h>
using namespace std;

// Brute Force : O(N ^ 3)

// Need 2 points to find slope
// Compare it with slope of 3rd point

class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    int n = points.size();

    if (n == 1)
      return 1;

    int res = 0;

    for (int i = 0; i < n; i++) {       // (x1, y1)
      for (int j = i + 1; j < n; j++) { // (x2, y2)
        int cnt = 2;
        int dx = (points[j][0] - points[i][0]);
        int dy = (points[j][1] - points[i][1]);

        /*
          dy/dx == dY/dX
          dx*dY == dy*dX
        */

        for (int k = 0; k < n; k++) {
          if (i != k && j != k) { // (x3, y3)
             
            int dX = (points[k][0] - points[i][0]);
            int dY = (points[k][1] - points[i][1]);

            if (dx * dY == dy * dX)
              cnt++;
          }
        }

        res = max(res, cnt);
      }
    }

    return res;
  }
};

//! Using STL - Tan 

class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();

    if(n == 1)
      return 1;

    int maxCnt = 0; 

    for(int i = 0; i < n; i++){
      unordered_map<double, int> mp;
    
      for(int j = 0; j < n; j++){

        if(i == j)
          continue;

        auto dy = points[j][1] - points[i][1];
        auto dx = points[j][0] - points[i][0]; 
        auto theta = atan2(dy, dx);
        
        mp[theta]++;
        maxCnt = max(maxCnt, mp[theta] + 1); // * ---- * (theta) but we are counting points so +1 
      }
    }

    return maxCnt;    
  }
};

//! Using string as key 

class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();

    if(n == 1)
      return 1;

    int maxCnt = 0; 

    for(int i = 0; i < n; i++){
      unordered_map<string, int> mp;
    
      for(int j = 0; j < n; j++){

        if(i == j)
          continue;

        auto dy = points[j][1] - points[i][1];
        auto dx = points[j][0] - points[i][0]; 
        auto theta = atan2(dy, dx);

        auto gcd = __gcd(dy, dx);
        string key = to_string(dx/gcd) + "_" + to_string(dy/gcd);
        mp[key]++;
        
        maxCnt = max(maxCnt, mp[key] + 1); // * ---- * (theta) but we are counting points so +1 
      }
    }

    return maxCnt;    
  }
};