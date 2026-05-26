#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {
  set<pair<int,int>> st;

  for(auto &p : points){
    st.insert({p[0],p[1]});
  }

  int n = points.size();

  int ans = INT_MAX;

  // Trying every pair as diagonal - since they are unique in rectangle
  // Ex : (1,1) (5,3) are diagonal points
  // If out set has (1,3) x1,y2 & (5,1) x2,y1 then its a valid rectangle

  for(int i = 0; i < n; i++){
    int x1 = points[i][0];
    int y1 = points[i][1];

    for(int j = i + 1; j < n; j++){
      int x2 = points[j][0];
      int y2 = points[j][1];

      if(x1 == x2 || y1 == y2) continue;

      // (x1,y2) (x2,y1)
      if(st.count({x1,y2}) && st.count({x2,y1})){
        int area = abs(x1-x2) * abs(y1-y2);
        ans = min(area, ans);
      }
    }
  }

  return ans == INT_MAX ? 0 : ans;
  } 
};