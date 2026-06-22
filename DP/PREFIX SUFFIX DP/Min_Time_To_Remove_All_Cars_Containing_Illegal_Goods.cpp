#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumTime(string s) {
  int n = s.size();
  vector<int> left(n, 0), right(n, 0);

  if(s[0] == '1') left[0] = 1;
  for(int i = 1; i < n; i++){
    if(s[i] == '1') 
      left[i] = min(left[i - 1] + 2, i + 1); // min(remove left + mid, remove everything from left)
    else 
      left[i] = left[i - 1]; 
  }

  if(s[n - 1] == '1') right[n - 1] = 1;
  for(int i = n - 2; i >= 0; i--){
    if(s[i] == '1') 
      right[i] = min(right[i + 1] + 2, n - i); // min(remove right + mid, remove everything from right)
    else 
      right[i] = right[i + 1];
  }

  int ans = 1e9;
  ans = min(left[n - 1], right[0]); // min(left / left + mid, right / right + mid)

  for(int i = 1; i <= n-2; i++)
    ans = min(ans, left[i] + right[i + 1]); // Upto i removed using left / left + mid || From (i+1 -> n) removed using right / right + mid

  return ans;
  }
};


//! Compressed DP 

class Solution {
public:
  int minimumTime(string s) {
  int n = s.size();
  int dp = 0;
  int ans = n; // remove all from one side

  for(int i = 0; i < n; i++){
    if(s[i] == '1')
      dp = min(dp + 2, i + 1); // min(left + mid, whole left)
      
    ans = min(ans, dp + n - i - 1); // + whole right
  }

  return ans;
  }
};