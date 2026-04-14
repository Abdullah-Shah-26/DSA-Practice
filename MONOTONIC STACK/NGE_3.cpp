#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//! TC = O(Log(N)) | SC = O(Log(N)) where LogN = No of digits in N

class Solution{
  public:
  int nextGreaterElement(int n){
  
  string s = to_string(n);  
  int m = s.size();

  int i = m - 2; 
  //* Find rightmost smallest dip where increase is possible
  while(i >= 0 && s[i] >= s[i + 1]){
    i--;
  }
  
  if(i == -1) // No increase possible
    return -1; 

  //* Find rightmost elem towards i that is just > s[i]
  int j = m-1;
  while(j > i && s[j] <= s[i]){
    j--;
  }

  swap(s[i], s[j]);
  reverse(s.begin() + i + 1, s.end());

  ll x = stoll(s);
  if(x > INT_MAX)
    return -1;

  return x;
  }
};