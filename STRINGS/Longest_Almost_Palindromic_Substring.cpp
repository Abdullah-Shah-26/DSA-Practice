#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
  4 Cases :
    Odd center
    delete left
           right

    Even center
    delete left
           right
  */

  int almostPalindromic(string s) {
    int n = s.size();
    int maxi = 2;

    for (int i = 0; i < n; i++) {
      int j = i - 1;
      int k = i + 1;
      bool flag = true;

      while (j >= 0 && k < n) {
        if (s[j] != s[k]) {
          if (flag) { // Delete left
            flag = false;
            j--;
          } else // Cannot delete more than once
            break;
        } else {
          maxi = max(maxi, k - j + 1);
          if ((k < n - 1 || j > 0) && flag) {
            maxi = max(maxi, k - j + 2);
          }
          j--;
          k++;
        }
      }

      j = i - 1;
      k = i + 1;
      flag = true;

      while (j >= 0 && k < n) {
        if (s[j] != s[k]) {
          if (flag) { // Delete right
            flag = false;
            k++;
          } else
            break;
        } else {
          maxi = max(maxi, k - j + 1);
          if ((k < n - 1 || j > 0) && flag) {
            maxi = max(maxi, k - j + 2);
          }
          j--;
          k++;
        }
      }

      j = i;
      k = i + 1;
      flag = true;

      while (j >= 0 && k < n) {
        if (s[j] != s[k]) {
          if (flag) {
            flag = false;
            j--;
          } else
            break;
        } else {
          maxi = max(maxi, k - j + 1);
          if ((k < n - 1 || j > 0) && flag) {
            maxi = max(maxi, k - j + 2);
          }
          j--;
          k++;
        }
      }

      j = i;
      k = i + 1;
      flag = true;

      while (j >= 0 && k < n) {
        if (s[j] != s[k]) {
          if (flag) {
            flag = false;
            k++;
          } else
            break;
        } else {
          maxi = max(maxi, k - j + 1);
          if ((k < n - 1 || j > 0) && flag) {
            maxi = max(maxi, k - j + 2);
          }
          j--;
          k++;
        }
      }
    }

    return maxi;
  }
};