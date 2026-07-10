#include <bits/stdc++.h>
using namespace std;

// MOORE'S VOTING ALGORITHM
// TC = O(n) | SC = O(1)

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int votes = 0;

    for (int num : nums) {
      if (votes == 0)
        candidate = num;

      if (num == candidate)
        votes++;
      else
        votes--;
    }

    return candidate;
  }
};