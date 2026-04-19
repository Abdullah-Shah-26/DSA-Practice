#include <bits/stdc++.h>
using namespace std;

//! NGE
// TC = O(N*2) | SC = O(N)

class Solution {
  public:

    vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();

    // Using vector as stack
    vector<int> st; // Monotonic Decreasing Stack
    vector<int> ans(n, 0);

    for(int i = n-1; i >= 0; i--){

      while(!st.empty() && temp[st.back()] <= temp[i]){
        st.pop_back();
      }

      ans[i] = (st.empty()) ? 0 : st.back() - i;

      st.push_back(i);
    }

    return ans;
    }
}; 
