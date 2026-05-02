#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)

class Solution {
  public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    int n = cars.size();    

    vector<double> ans(n, -1.0);
    stack<int> st; // stores idx of cars ahead

    for(int i = n-1; i >= 0; i--){
      int p1 = cars[i][0]; // Current Car Pos, Speed
      int s1 = cars[i][1];

      while(!st.empty()){
        int j = st.top();
        int p2 = cars[j][0]; // Ahead Car Pos, Speed
        int s2 = cars[j][1];

        // Cur Car cannot catch ahead car
        if(s1 <= s2){
          st.pop();
          continue;
        }

        // Time req to catch ahead car
        double t = (double)(p2 - p1)/(s1 - s2);

        // No one collided with ahead car - so we can collide
        if(ans[j] == -1 || t <= ans[j]){
          ans[i] = t;
          break;
        }

        // Someone collided it before me
        st.pop();
      }

      st.push(i);
    }

    return ans;
    }
};