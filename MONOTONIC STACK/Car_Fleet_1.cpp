#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN) | SC = O(N)

class Solution {
  public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
  int n = position.size();

  vector<pair<int,int>> a;

  for(int i = 0; i < n; i++){
    a.push_back({position[i], speed[i]});
  }    

  sort(begin(a), end(a));

  // Scanning cars from nearest to farthest from target
  // [4, 12, 20]

  // dist = speed * time
  // time = dist/speed 

  stack<double> st; // Monotonic Increasing Stack - Fleet Time Tracker

  for(int i = n-1; i >= 0; i--){
    auto [pos, s] = a[i];

    double t = (double)(target - pos)/s;
      
    if(st.empty() || t > st.top()){ // Current Car Cannot Catch Up With Fleet
      st.push(t); // New Fleet Starts
    }
  }

  return (int)st.size();
  }
};