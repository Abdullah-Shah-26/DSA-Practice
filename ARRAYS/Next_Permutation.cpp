#include <bits/stdc++.h>
using namespace std;

// Similar to NGE 3
// TC = O(N)
// SC = O(1)

class Solution {
  public:
    void nextPermutation(vector<int>& a) {
    int n = a.size();

    // Find the dip position while traversing R to L.
    int pos = -1;
    for(int i = n-1; i >= 1; i--){
      if(a[i - 1] < a[i]){
        pos = i-1;
        break;
      }
    }

    if(pos == -1){
      reverse(a.begin(), a.end());
      return; 
    }

    // Find the next greater element than dip from right
    for(int i = n-1; i > pos; i--){
      if(a[pos] < a[i]){
        swap(a[pos], a[i]);
        break;
      }
    }

    reverse(a.begin() + pos + 1, a.end());
    }
};