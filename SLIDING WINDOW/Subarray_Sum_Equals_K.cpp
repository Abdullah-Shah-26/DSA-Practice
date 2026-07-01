#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // TC = O(n^3)
  int countSubarrays(vector<int> &arr, int k) {
    int total = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int sum = 0;

        for (int k = i; k <= j; ++k) {
          sum += arr[k];
        }
        if (sum == k)
          total++;
      }
    }
    return total;
  }
};

class Solution {
public: // TC = O(n ^ 2)
  int countSubarrays(vector<int> &arr, int k) {
    // code here
    int total = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += arr[j];

        if (sum == k)
          total++;
      }
    }
    return total;
  }
};

class Solution {
public:
  // prefix sum approach - sliding window protocol - map
  int countSubarrays(vector<int> &arr, int k) {
    unordered_map<int, int> m; // key as prefix sum - value as count
    m[0] = 1;
    int prefixsum = 0;
    int total = 0;

    for (int i = 0; i < arr.size(); i++) {
      prefixsum += arr[i];

      if (m.count(prefixsum -
                  k)) // if prefixsum - k = x got repeated atlaest once then
      {               // subarr sum from x to prefix sum = k
        total += m[prefixsum - k];
        m[prefixsum]++;
      } else
        m[prefixsum]++; // prefix sum seeing first time put in map
    }
    return total;
  }
};