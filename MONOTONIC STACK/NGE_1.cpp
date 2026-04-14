#include<bits/stdc++.h>
using namespace std;

//! TC = O(2N) | SC = O(N)

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
    int n=arr.size();

    vector<int>NGE(n,-1);
    stack<int>st;

    for(int i = n-1;i >= 0; i--)
    {   
        while(!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if(st.empty())
            NGE[i] = -1;
        else
            NGE[i] = st.top();
        
        st.push(arr[i]);
    }
    return NGE;
    }
};