#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxRectangleArea(vector<vector<int>>& points) {
  set<pair<int,int>> st;
  int maxArea = -1;

  for(auto &p : points){
    st.insert({p[0], p[1]});
  }    

  int n = points.size();

  // Diagonals of rectangle can never be same

  for(int i = 0; i < n; i++){
    int x1 = points[i][0];
    int y1 = points[i][1];

    for(int j = i + 1; j < n; j++){
      int x2 = points[j][0];
      int y2 = points[j][1];

      if((x1 == x2) || (y1 == y2)){
        continue;
      }

      if(st.count({x1,y2}) && st.count({x2,y1})){
        int left = min(x1,x2);
        int right = max(x1,x2);
        int top = max(y1,y2);
        int bottom = min(y1,y2);
      
        bool valid = true;

        for(auto &p : points){
          int x = p[0];
          int y = p[1];

          // Skip rectangle corners
          if((x == x1 && y == y1) || (x == x1 && y == y2) || (x == x2 && y == y1) || (x == x2 && y == y2)) continue;

          
          if(x >= left && x <= right && y >= bottom && y <= top){
            valid = false;
            break;
          }
        }

        if(valid){
          int area = abs(x1 - x2) * abs(y1 - y2);
          maxArea = max(maxArea, area);
        }
      }
    }
  }

  return maxArea;
  }
};