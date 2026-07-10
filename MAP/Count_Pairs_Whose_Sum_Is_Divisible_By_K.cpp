#include <bits/stdc++.h>
using namespace std;

/*
a = q1 * k + r1
b = q2 * k + r2

r1 = a mod k
r2 = b mod k

(a + b) = (q1 + q2) k + (r1 + r2)

(q1 + q2)*k is always divisible by k

(a + b) mod k = (r1 + r2) mod k

Property : (a + b) mod k = ((a mod k) + (b mod k)) mod k
*/

class Solution {
public:
  int countKdivPairs(vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;
    vector<int> freq(k + 1, 0);

    for (int i = 0; i < n; i++) {
      int rem = arr[i] % k;
      int need = (k - rem) % k;
      cnt += freq[need];
      freq[rem]++;
    }

    return cnt;
  }
};