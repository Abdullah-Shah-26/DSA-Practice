#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> ans(n, -1);
    stack<int> st; //! Monotonic Increasing Stack
    
    for(int i = n-1; i >= 0; i--){
        
        while(!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }
        
        ans[i] = (st.empty()) ? -1 : arr[st.top()];
        
        st.push(i);
    }   
    
    return ans;
    }
};