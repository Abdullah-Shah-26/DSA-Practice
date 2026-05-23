#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool search(vector<int>& a, int target) {
  
  int l = 0, r = a.size() - 1;

  while(l <= r){
    int mid = (l + r) >> 1;

    if(a[mid] == target)
      return true;

    if(a[l] == a[mid] && a[mid] == a[r]){
      l++;
      r--;
      continue;
    }

    // Left half sorted
    if(a[l] <= a[mid]){
      
      // Does target lie in left half
      if(a[l] <= target && target < a[mid])
        r = mid - 1;
      else 
        l = mid + 1;
    }

    // Right half sorted
    else{

      // Does target lie in right half
      if(a[mid] < target && target <= a[r])
        l = mid + 1;
      else 
        r = mid - 1;
    }
      
  }

  return false;
  }
};