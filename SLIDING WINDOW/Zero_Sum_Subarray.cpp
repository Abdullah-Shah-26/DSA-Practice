#include <bits/stdc++.h>
using namespace std;

int findSubarray(vector<int> &arr) {
  // prefix sum approach - and using unordered map - TC = O(n)
  int total = 0; // total no of subarrays that have sum as 0
  int n = arr.size();

  // map will store (key)prefixsum & count (value) (how many times it got
  // repeated)

  unordered_map<int, int> m;
  int prefixsum = 0;
  // inititalize map with (0,1) - to handle edge case where prefix sum is 0
  m[0] = 1;

  for (int i = 0; i < n; ++i) {
    prefixsum += arr[i];
    // if prefix sum got repeated before then the net sum in between = 0 ie sum
    // of that subarray is 0 add in total
    if (m.count(prefixsum)) { // m[key] -- gives access to value
      total += m[prefixsum];  // gives acces to the count of how many times that
                              // prefix sum got repeated
      m[prefixsum]++;         // increase the count of that prefix sum
    } else {
      m[prefixsum] = 1; // we are encountering that prefix sum first time so its
                        // count is 1 put in map
    }
  }
  return total;
};