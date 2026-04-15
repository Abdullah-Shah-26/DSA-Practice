#include <bits/stdc++.h>
using namespace std;

//! Brute Force

class Solution {
  public:
    int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if(nums[i] <= nums[j]){
          ans = max(ans, j - i);
        }
      }
    }

    return ans;
    }
};

//! 2 Pass Monotonic Stack

class Solution {
  public:
    int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    stack<int> st; // Monotonic Decreasing Stack

    // Choose best starts
    for(int i = 0; i < n; i++){
      if(st.empty() || nums[i] < nums[st.top()]){
        st.push(i);
      }
    }

    // Assign Best Ends
    for(int j = n-1; j >= 0; j--){
    // j is finding best possible i until condition remains valid
      while(!st.empty() && nums[st.top()] <= nums[j]){
        ans = max(ans, j - st.top());
        st.pop();
      }
    }

    return ans;
    }
};