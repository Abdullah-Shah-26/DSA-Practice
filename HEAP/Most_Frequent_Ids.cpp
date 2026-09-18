#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, int>;

class Solution {
public:
  vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq) {
    
    vector<long long> ans;
    unordered_map<int, long long> m;
    priority_queue<P> pq;

    int n = nums.size();

    for (int i = 0; i < n; i++) {
      m[nums[i]] += freq[i];

      // Add new entry
      pq.push({m[nums[i]], nums[i]});

      // Remove stale entry
      while (!pq.empty() && m[pq.top().second] != pq.top().first)
        pq.pop();

      ans.push_back(pq.top().first);
    }

    return ans;
  }
};