#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& a) {
    
  int ans = INT_MAX;
  int n = a.size();

  int l = 0, r =  n-1;

  // Min lies in unsorted half
  while(l <= r){
    
    // Entire half is sorted
    // Left is min element 
    if(a[l] <= a[r]){
      ans = min(ans, a[l]);
      break;
    }

    int mid = (l + r) >> 1;

    // Left half sorted
    if(a[l] <= a[mid]){
      ans = min(ans, a[l]);
      l = mid + 1;
    }

    // Right half sorted
    else{
      ans = min(ans, a[mid]);
      r = mid - 1;
    }
  }
  
  return ans;
  }
};