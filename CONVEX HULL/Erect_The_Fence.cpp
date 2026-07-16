#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Cross Product
  int findEqVal(vector<int> &p1, vector<int> &p2, vector<int> p3){
    int x1 = p1[0];
    int x2 = p2[0];
    int x3 = p3[0];

    int y1 = p1[1];
    int y2 = p2[1];
    int y3 = p3[1];

    return (y3 - y2)*(x2 - x1) - (y2 - y1)*(x3 - x2);
  }

  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    sort(begin(trees), end(trees));
    
    vector<vector<int>> ans;
    deque<vector<int>> lower, upper;

    for(auto &p : trees){
      int l = lower.size();
      int u = upper.size();

      while(l >= 2 && findEqVal(lower[l-2], lower[l-1], {p[0], p[1]}) < 0){
        l--;
        lower.pop_back();
      }
      
      while(u >= 2 && findEqVal(upper[u-2], upper[u-1], {p[0], p[1]}) > 0){
        u--;
        upper.pop_back();
      } 

      upper.push_back({p[0], p[1]});
      lower.push_back({p[0], p[1]});
    }

    for(auto &l : lower) 
      ans.push_back(l);

    for(auto &u : upper) 
      ans.push_back(u);

    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));

    return ans;
  }
};
