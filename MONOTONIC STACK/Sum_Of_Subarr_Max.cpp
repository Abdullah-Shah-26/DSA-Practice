#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:

  using ll = long long;

  int sumOfMax(vector<int> &arr){
  int n = arr.size();    
    
  vector<int> NGE(n), PGE(n);
  stack<int> st;

  // Previous Strictly Greater Element
  for(int i = 0; i < n; i++){
    while(!st.empty() && arr[st.top()] <= arr[i]){
      st.pop();
    }  

    PGE[i] = st.empty() ? -1 : st.top();

    st.push(i);
  }

  while(!st.empty()) st.pop();

  // Next Greater or Equal Element
  for(int i = n-1; i >= 0; i--){
    while(!st.empty() && arr[st.top()] < arr[i]){
      st.pop();
    }

    NGE[i] = st.empty()  ? n : st.top();

    st.push(i);
  }

  ll res = 0;

  for(int i = 0; i < n; i++){
    int left = i - PGE[i];
    int right = NGE[i] - i;

    res = (res + (left * right * 1LL * arr[i]));
  }
  }
};