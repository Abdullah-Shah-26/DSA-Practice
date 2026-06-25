#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumLines(vector<vector<int>>& points) {
  
  // Edge Cases : 
  // Slope = (y2 - y1)/(x2 - x1)
  // If we find all the slopes, we might get precision error while dividing 
  // We can maintain pair [[y2-y1],[x2-x1]] the ratio needs to be same
  // Ex : [4, 6] == [2, 2] has correct ratio but values are diff, to handle this divide by gcd 
  // If one -ve always make first co-ordinate -ve if there exist like [2,-3] --->> [-2,3]  
  // If both -ve make them +ve

  int n = points.size();
  sort(begin(points), end(points));
  
  vector<pair<int,int>> slopes;
  
  for(int i = 1; i < n; i++){
    int dx = (points[i][0] - points[i - 1][0]);
    int dy = (points[i][1] - points[i - 1][1]);

    int gcd = __gcd(abs(dx), abs(dy));
    dx /= gcd, dy /= gcd; // Divide by GCD so all equivalent slopes have the same (dy, dx) representation.

    if(dx < 0 && dy < 0){
      dx = abs(dx);
      dy = abs(dy);
    }
    else if(dx > 0 && dy < 0){ 
      dx = -dx;
      dy = dy;
    }

    slopes.push_back({dx, dy});
  }

  int ans = 0;

  while(!slopes.empty()){
    auto cur = slopes.back();

    // Equal slopes - same line segment can connect all points
    while(!slopes.empty() && slopes.back() == cur)
      slopes.pop_back();

    ans++;
  }

  return ans;
  }
};