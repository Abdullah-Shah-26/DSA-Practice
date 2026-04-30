#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN) | SC = O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();

    sort(begin(nums), end(nums));

    int freq = 1, cnt = 0;
    for(int i = 1; i < n; i++){
      if(nums[i] == nums[i-1]){
        freq++;
      } 
      else{
        if(freq == 1)
            return -1;

        cnt += ceil(freq/3.0);

        freq = 1;
      } 
    } 

    // Edge Cases : if loop doenst run or we never get diff element

    if(freq == 1) // Edge Case : [2]
      return -1;

    cnt += ceil(freq/3.0); // Edge Case [2 2 2 2 2 2]      

    return cnt;
    }
}; 