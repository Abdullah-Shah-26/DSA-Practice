#include <bits/stdc++.h>
using namespace std;

// TC = O(N*K + N^2)
// SC = O(N)

class Solution {
  public:
    int n;
    string nextPerm(string &num, int k){
      string nums = num;
     
      while(k--){ // O(K * N)
      int pos = -1;

      for(int i = n-1; i >= 1; i--){
        if(nums[i-1] < nums[i]){
          pos = i-1;
          break;
        }
      }

      if(pos == -1){
        reverse(begin(nums), end(nums));
        continue;
      }

      // Find just greater digit from right to swap
      for(int i = n-1; i > pos; i--){
        if(nums[pos] < nums[i]){
          swap(nums[pos], nums[i]);
          break;
        }
      }

      reverse(nums.begin() + pos + 1, nums.end());
    }

    return nums;
    }

    int getMinSwaps(string nums, int k) {
    int cnt = 0;
    n = nums.size();
    
    string s = nums; // Original String 
    string perm = nextPerm(nums, k); // Desired String  

    // Count Swaps
    for(int i = 0; i < n; i++){ // O(N^2)
      if(s[i] != perm[i]){
        int j = i;

        // Until i dont find matching chars again j++
        while(s[j] != perm[i]){
          j++;
        }

        // Bring that char to i
        while(j > i){
          swap(s[j], s[j-1]);
          j--;
          cnt++;
        }
      }
    }

    return cnt;    
    }
};