#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string kthLargestNumber(vector<string> &nums, int k) {
    auto cmp = [](string a, string b) {
      if (a.size() == b.size())
        return a > b;

      return a.size() > b.size();
    };

    // decltype(cmp) = Type of comparator 
    priority_queue<string, vector<string>, decltype(cmp)> minHeap;

    for (int i = 0; i < nums.size(); i++) {
      minHeap.push(nums[i]);

      if (minHeap.size() > k)
        minHeap.pop();
    }

    return minHeap.top();
  }
};