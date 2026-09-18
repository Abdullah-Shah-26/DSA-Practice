#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long minimumDifference(vector<int> &nums) {
    int n = nums.size();
    int k = n / 3;

    vector<ll> prefMin(n), suffMax(n);
    priority_queue<int> maxHeap;                            // For smallest k
    priority_queue<int, vector<int>, greater<int>> minHeap; // For largest k

    ll pref = 0, suff = 0, minDiff = LLONG_MAX;

    for (int i = 0; i < k; i++) {
      maxHeap.push(nums[i]);
      pref += nums[i];
    }

    prefMin[k - 1] = pref;

    for (int i = k; i < n - k; i++) {
      if (!maxHeap.empty() && nums[i] < maxHeap.top()) {
        pref += (nums[i] - maxHeap.top());
        maxHeap.pop();
        maxHeap.push(nums[i]);
      }

      prefMin[i] = pref;
    }

    for (int i = n - 1; i >= n - k; i--) {
      minHeap.push(nums[i]);
      suff += nums[i];
    }

    suffMax[n - k] = suff;

    for (int i = n - k - 1; i >= k - 1; i--) {
      if (!minHeap.empty() && nums[i] > minHeap.top()) {
        suff += (nums[i] - minHeap.top());
        minHeap.pop();
        minHeap.push(nums[i]);
      }

      suffMax[i] = suff;
    }

    for (int i = k - 1; i < n - k; i++)
      minDiff = min(minDiff, prefMin[i] - suffMax[i + 1]);

    return minDiff;
  }
};