#include <bits/stdc++.h>
using namespace std;

// NSE + PSE + Largest Area of Histogram + PrefSum

class Solution {
public:
  int n;
  vector<int> NSE(vector<int> &arr){
    vector<int> nse(n, n);

    stack<int> st;

    for(int i = n-1; i >= 0; i--){
      
      while(!st.empty() && arr[st.top()] >= arr[i]){
        st.pop();
      }

      if(!st.empty()){
        nse[i] = st.top();
      }

      st.push(i);
    }

    return nse;
  }

  vector<int> PSE(vector<int> &arr){
    vector<int> pse(n, -1);

    stack<int> st;

    for(int i = 0; i < n; i++){
      
      while(!st.empty() && arr[st.top()] >= arr[i]){
        st.pop();
      }

      if(!st.empty()){
        pse[i] = st.top();
      }

      st.push(i);
    }

    return pse;
  }

  int largestRectangleArea(vector<int>& heights) {
    n = heights.size();

    vector<int> nse = NSE(heights);
    vector<int> pse = PSE(heights);

    int maxArea = 0;
    for(int i = 0; i < n; i++){
      maxArea = max(maxArea, (nse[i] - pse[i] - 1) * heights[i]);
    }

    return  maxArea;
  }

  int maximalRectangle(vector<vector<char>>& mat) {
  int N = mat.size();
  int M = mat[0].size();

  vector<vector<int>> pref(N, vector<int> (M, 0));

  for(int j = 0; j < M; j++){
    int sum = 0;
    
    for(int i = 0; i < N; i++){
      if(mat[i][j] == '0') sum = 0;
      else sum += mat[i][j] - '0';

      pref[i][j] = sum;
    }
  }

  int ans = 0;

  for(int i = 0; i < N; i++){
    ans = max(ans, largestRectangleArea(pref[i]));
  }

  return ans;
  }
};