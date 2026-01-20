#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>>ans;
    priority_queue<pair<int,pair<int,int>>>pq;

    for(int i = 0;i < points.size(); i++)
    {
      long long x = points[i][0];
      long long y = points[i][1];
      pq.push({ (x*x) + (y*y),{x,y}});

      if(pq.size() > k)
      pq.pop();
    }    

    while(!pq.empty())
    {
      auto it = pq.top();
      pq.pop();
      ans.push_back({it.second.first,it.second.second});
    }
    return ans;

    }
};