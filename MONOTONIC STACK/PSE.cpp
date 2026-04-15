#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//* Previous Smaller Element
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> ans(n,-1);
    stack<int> st; //! Monotonic Increasing Stack
    
    for(int i = 0; i < n; i++){
        while(!st.empty() &&  arr[i] <= arr[st.top()]){
            st.pop();
        }
        
        ans[i] = (st.empty()) ? -1 : arr[st.top()];
        
        st.push(i);
    }
    
    return ans; 
    }
};