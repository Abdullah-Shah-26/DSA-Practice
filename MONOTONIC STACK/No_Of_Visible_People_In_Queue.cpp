#include <bits/stdc++.h>
using namespace std;

//! Brute Force
class Solution{
  public: 
    vector<int> canSeePersonsCount(vector<int>& a) {
     
    int n = a.size();
    vector<int> ans(n,0);

    for(int i = 0; i < n; i++){
      int maxBetween = INT_MIN;

      for(int j = i + 1; j < n; j++){
        if(maxBetween < min(a[i], a[j])){
          ans[i]++;
        }

        maxBetween = max(maxBetween, a[j]);
        
        if(a[j] >= a[i]) break; // j will block i's view and no one after j can see i
      }
    }

    return ans;
    }
};

//! Monotonic Decreasing Stack 
//* TC = O(N) | SC = O(N)

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int>& a) {
  int n = a.size();
  
  vector<int> ans(n,0);
  stack<int> st; 

  for(int i = 0; i < n; i++){
    
    // prevHt <= CurHt then cur wont let prev see future ht's except itself
    while(!st.empty() && a[st.top()] <= a[i]){
      ans[st.top()]++;
      st.pop();
    }

    if(!st.empty()){ // I am taller than CurHt so i can see it & I also can block future Ht's
      ans[st.top()]++;
    }

    st.push(i);
  }

  return ans;
  }
};