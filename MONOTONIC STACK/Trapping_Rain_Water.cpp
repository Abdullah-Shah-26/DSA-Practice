#include <bits/stdc++.h>
using namespace std;

//! Prefix + Suffix - Max
//* TC = O(N) | SC = O(N)

class Solution {  
  public:
    int trap(vector<int>& height) {
    int n = height.size();

    vector<int> leftMax(n,0), rightMax(n,0);

    leftMax[0] = height[0];
    for(int i = 1; i < n; i++){
      leftMax[i] = max(leftMax[i-1], height[i]);
    }      

    rightMax[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--){
      rightMax[i] = max(rightMax[i+1], height[i]);
    }

    int water = 0;
    for(int i = 0; i < n; i++){
      water +=  min(leftMax[i], rightMax[i]) - height[i];
    }

    return water;
    }
};

//! 2 Pointer + Running Prefix Suffix Max
//* TC = O(N) | SC = O(1)

class Solution {  
  public:
    int trap(vector<int>& height) {
    
    int n = height.size();
    int water = 0;

    int l = 0, r = n-1;
    int leftMax = 0, rightMax = 0;

  // A bar can have water on top of it and surrounded by maxGuys so l == r may also has water so L <= R 
    while(l <= r){

    // Smaller Boundary decides water - So process it first
      if(leftMax < rightMax){
      leftMax = max(leftMax, height[l]);  
      water += leftMax - height[l];
      l++;
      }
      
      else{
      rightMax = max(rightMax, height[r]);
      water += rightMax - height[r];
      r--;
      }
    }

    return water;
    }
};

//! Monotonic Stack
//* TC = O(N) | SC = O(N)

class Solution {
  public:
    int trap(vector<int>& height) {
    int n = height.size();
    int water = 0;
    stack<int> st; // Monotonic Decreasing stack

    for(int i = 0; i < n; i++){

      // Found Right boundary
      while(!st.empty() && height[st.top()] < height[i]){
        int mid = st.top(); // valley bottom pt
        st.pop();

        if(st.empty()) break; // No Left Boundary

        int left = st.top();
        int right = i;
        int width = right - left - 1;

        int boundedHt = min(height[left], height[right]) - height[mid];

        water += boundedHt*width;
      } 

      st.push(i);
    }
    return water;
    }
};