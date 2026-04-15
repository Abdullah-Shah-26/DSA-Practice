#include <bits/stdc++.h>
using namespace std;

//! TC = O(N) | SC = O(2*N)

class Solution {
  public:
    vector<int> getNSE(vector<int> &a, int n){
      vector<int> right(n);
      stack<int> st; // Monotonic Increasing

      for(int i = n-1; i >= 0; i--){
        while(!st.empty() && a[st.top()] >= a[i]){
          st.pop();
        }

        right[i] = (st.empty()) ? n : st.top();
        st.push(i);
      }
      return right; 
    }

    vector<int> getPSE(vector<int> &a, int n){
      vector<int> left(n);
      stack<int> st;

      for(int i = 0; i < n; i++){
        while(!st.empty() && a[st.top()] >= a[i]){
          st.pop();
        }

        left[i] = (st.empty()) ? -1 : st.top();
        st.push(i); 
      }
      return left;
    }

    int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Stores indices of next & prev smaller element of each i
    vector<int> right = getNSE(nums, n);
    vector<int> left = getPSE(nums, n);

    int ans = 0;

    for(int i = 0; i < n; i++){
      if(left[i] < k && k < right[i]){
        int len = right[i] - left[i] - 1;
        ans = max(ans, len * nums[i]); // nums[i] is the min 
      }
    }

    return ans;
    }
};