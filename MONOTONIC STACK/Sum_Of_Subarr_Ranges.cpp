#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n;
  using ll = long long;

  ll sumOfSubarrMin(vector<int> &arr){
    vector<int> NSE(n), PSEE(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
      while(!st.empty() && arr[st.top()] >= arr[i]){
        st.pop();
      }

      NSE[i] = st.empty() ? n : st.top();

      st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = 0; i < n; i++){
      while(!st.empty() && arr[st.top()] > arr[i]){
        st.pop();
      }

      PSEE[i] = st.empty() ? -1 : st.top();

      st.push(i);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
      int l = i - PSEE[i];
      int r = NSE[i] - i;

      ans = (ans + (l * r * 1LL * arr[i]));
    }

    return ans;
  }

  ll sumOfSubarrMax(vector<int> &arr){
    vector<int> NGEE(n), PGE(n);
    stack<int> st;

    for(int i = 0; i < n; i++){
      while(!st.empty() && arr[st.top()] <= arr[i]){
        st.pop();
      }

      PGE[i] = st.empty() ? -1 : st.top();

      st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n-1; i >= 0; i--){
      while(!st.empty() && arr[st.top()] < arr[i]){
        st.pop();
      }

      NGEE[i] = st.empty() ? n : st.top();

      st.push(i);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
      int l = i - PGE[i];
      int r = NGEE[i] - i;

      ans = (ans + (l * r * 1LL * arr[i]));
    }

    return ans;
  }

  long long subArrayRanges(vector<int>& nums) {
    n = nums.size();
    return sumOfSubarrMax(nums) - sumOfSubarrMin(nums);    
  }
};