#include <bits/stdc++.h>
using namespace std;

// Sliding Window + Priority Queue

using P = pair<int, int>;

class Solution {
public:
  int findTopXSum(unordered_map<int, int> &m, int x) {
    priority_queue<P, vector<P>, greater<P>> pq;

    for (auto [val, freq] : m) {
      pq.push({freq, val});

      if (pq.size() > x)
        pq.pop();
    }

    int sum = 0;
    while (!pq.empty()) {
      auto [val, freq] = pq.top();
      pq.pop();

      sum += val * freq;
    }

    return sum;
  }

  vector<int> findXSum(vector<int> &nums, int k, int x) {
    int n = nums.size();

    vector<int> ans;

    unordered_map<int, int> m;

    int l = 0;

    for (int r = 0; r < n; r++) {
      m[nums[r]]++;

      if (r - l + 1 == k) {
        ans.push_back(findTopXSum(m, x));

        m[nums[l]]--;

        if (m[nums[l]] == 0)
          m.erase(nums[l]);

        l++;
      }
    }

    return ans;
  }
};