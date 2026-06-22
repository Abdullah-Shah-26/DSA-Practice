#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
    int n = positions.size();

    map<int,int> mp; // [pos, idx]
    for(int i = 0; i < n; i++){
      mp[positions[i]] = i;
    }

    vector<int> ans;
    stack<int> st;

    // Now positions are processed in sorted order 
    for(auto &[pos, i]: mp){
      if(directions[i] == 'R') // R robot
        st.push(i);
      else{
        while(!st.empty() && health[i] > 0){
          int j = st.top(); // R robot
          st.pop();

          if(health[j] > health[i]){ // hp R > hp L 
            health[j] -= 1;
            health[i] = 0;
            st.push(j);
          }
          else if(health[j] < health[i]){ // hp R < hp L
            health[j] = 0;
            health[i] -= 1;
          }
          else{
            health[i] = 0;
            health[j] = 0;
          }
        }
      }
    }

    for(int i = 0; i < n; i++){
      if(health[i] > 0)
        ans.push_back(health[i]);
    }

    return ans;
  }
};