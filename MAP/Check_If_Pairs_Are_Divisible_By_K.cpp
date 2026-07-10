#include <bits/stdc++.h>
using namespace std;

/*
(a + b) % k == 0

r1 = a % k;
r2 = b % k;

(r1 + r2) == k
*/

class Solution {
public:
  bool canArrange(vector<int> &arr, int k) {
    vector<int> freq(k, 0); // remainders from [0...k-1]

    for (int x : arr) {
      int rem = (x % k + k) % k; // To handle -ve no's
      freq[rem]++;
    }

    if (freq[0] & 1)
      return false;

    for (int rem = 1; rem < (k + 1) / 2; rem++) {
      int counterHalf = k - rem;

      if (freq[counterHalf] != freq[rem])
        return false;
    }

    // Ex : k = 8, freq[k/2] Should be even to pair up
    if (k % 2 == 0 && (freq[k / 2] & 1))
      return false;

    return true;
  }
};