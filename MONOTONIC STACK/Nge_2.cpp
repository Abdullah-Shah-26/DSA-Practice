#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TC = O(2N + 2N) - push & pop in stack
// SC = O(2N + N) - stack + Nge

class Solution {
  public:
    vector<int> nextGreaterElements(vector<int>& a) {
    int n = a.size();

    vector<int> nge(n, -1);
    stack<int> st;
        
    for(int i = 2*n-1; i >= 0; i--){

      while(!st.empty() && a[i % n] >= st.top()){
        st.pop();
      }

      if(i < n){
        nge[i] = (st.empty()) ? -1 : st.top();
      }

      st.push(a[i % n]);
    }

    return nge;
    }
};