#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool dfs(int i, vector<int> &nums, vector<int> &bucket, int target) {

    if (i == nums.size())
      return true;

    for (int b = 0; b < bucket.size(); b++) {

      if (b > 0 && bucket[b] == bucket[b - 1]) // Pruning symmetric case
        continue;

      if (bucket[b] + nums[i] > target)
        continue;

      bucket[b] += nums[i]; // Do

      if (dfs(i + 1, nums, bucket, target)) // Explore
        return true;

      bucket[b] -= nums[i]; // Undo

      if (bucket[b] == 0)
        break;
    }

    return false;
  }

  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % k != 0)
      return false;

    sort(begin(nums), end(nums), greater<int>());

    int target = sum / k;

    vector<int> bucket(k, 0);

    return dfs(0, nums, bucket, target);
  }
};