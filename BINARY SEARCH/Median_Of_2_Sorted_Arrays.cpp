#include <bits/stdc++.h>
using namespace std;

// TC = O(log(min(m,n))) | SC = O(1)

class Solution {
public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {

    // Always binary search on smaller array
    if(a.size() > b.size())
      return findMedianSortedArrays(b, a);

    int m = a.size();
    int n = b.size();

    int total = m + n;
    int leftHalf = (total + 1) / 2;

    int l = 0;
    int r = m;

    while(l <= r){

      // How many elements we take from a
      int takeA = (l + r) >> 1;

      // Remaining from b
      int takeB = leftHalf - takeA;

      // Left side values
      int aLeft  = (takeA == 0) ? INT_MIN : a[takeA - 1];
      int bLeft  = (takeB == 0) ? INT_MIN : b[takeB - 1];

      // Right side values
      int aRight = (takeA == m) ? INT_MAX : a[takeA];
      int bRight = (takeB == n) ? INT_MAX : b[takeB];

      /*
        We need:

        aLeft <= bRight
        bLeft <= aRight

        Then partition is valid
      */

      if(aLeft <= bRight && bLeft <= aRight){

        // Odd length
        if(total & 1)
          return max(aLeft, bLeft);

        // Even length
        return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
      }

      // Took too many from a
      else if(aLeft > bRight){
        r = takeA - 1;
      }

      // Took too few from a
      else{
        l = takeA + 1;
      }
    }

    return 0.0;
  }
};