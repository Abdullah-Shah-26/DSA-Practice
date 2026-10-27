#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countStaircase(vector<int> &nums) {
    int n = nums.size();

    int mx = *max_element(begin(nums), end(nums));

    vector<int> freq(mx + 1), pos(mx + 1), seen(mx + 1);

    // Max distinct vals a stair case can have, based on n
    int maxK = 0;
    while (maxK * (maxK + 1) / 2 <= n)
      maxK++;

    maxK -= 1; // Max valid K

    int ans = 0;

    for (int st = 0; st < n; st++) {

      // No of vals whose cur freq == req freq acc to their pos
      int validCnt = 0;
      int distCnt = 0;

      for (int end = st; end < n; end++) {
        int val = nums[end];

        // Time stamping, mark val as visited during this iteration
        if (seen[val] != st + 1) {
          distCnt++;
          seen[val] = st + 1;
          pos[val] = distCnt;
          freq[val] = 1;

          if (distCnt > maxK)
            break;

          // 1st distinct value of subarr is already valid
          if (pos[val] == 1)
            validCnt++;
        } else {
          freq[val]++;

          if (freq[val] > pos[val])
            break;

          if (freq[val] == pos[val])
            validCnt++;
        }

        if (validCnt == distCnt)
          ans++;
      }
    }

    return ans;
  }
};