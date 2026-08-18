#include <bits/stdc++.h>
using namespace std;

// TC = O(N ^ 2)

class Solution {
public:
  bool check(vector<int> &nums, int cnt, int i, int dir) {
    int idx = i;

    vector<int> temp = nums;

    while (idx >= 0 && idx < nums.size() && cnt > 0) {
      if (temp[idx] > 0) {
        temp[idx]--;

        if (temp[idx] == 0)
          cnt--;

        dir *= -1;
      }

      idx += dir;
    }

    return cnt == 0;
  }

  int countValidSelections(vector<int> &nums) {
    int n = nums.size();

    int cnt = 0; // No of non zero elements

    for (int i = 0; i < n; i++)
      if (nums[i] != 0)
        cnt++;

    int ans = 0; // No of valid ways

    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        if (check(nums, cnt, i, -1)) // L
          ans++;

        if (check(nums, cnt, i, 1)) // R
          ans++;
      }
    }

    return ans;
  }
};

// Optimal :

class Solution {
public:
  int countValidSelections(vector<int>& nums) {
    int n = nums.size();

    int L = accumulate(begin(nums), end(nums), 0);
    int R = 0; 
    
    int ans = 0; 

    for(int i = 0; i < n; i++){
      L -= nums[i];
      R += nums[i];

      if(nums[i] == 0 && L == R){
        ans += 2;
      }
      else if(nums[i] == 0 && abs(L - R) == 1) // Edge Case : 
        ans += 1;
    }    

    return ans;
  }
};