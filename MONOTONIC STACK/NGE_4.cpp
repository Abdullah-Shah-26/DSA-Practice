#include <bits/stdc++.h>
using namespace std;

//! MultiStage Monotonic Stack
//* TC = O(N) | SC = O(N)
// Kth NGE would require K stacks, here K = 2 

class Solution {
  public:
    vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n, -1);

    vector<int> st1; // Waiting for 1st greater
    vector<int> st2; // Waiting for 2nd greater

    for(int i = 0; i < n; i++){

    // Indices that already got First NGE & waiting for 2nd NGE are in st2    
      while(!st2.empty() && nums[i] > nums[st2.back()]){
        ans[st2.back()] = nums[i];
        st2.pop_back();
      }

      // [Found 1st greater] - Move indices from st1 to st2 
      vector<int> temp;
      while(!st1.empty() && nums[i] > nums[st1.back()]){
        temp.push_back(st1.back());
        st1.pop_back();
      }

      for(int j = temp.size() - 1; j >= 0; j--){
        st2.push_back(temp[j]);
      }

      st1.push_back(i);
    }    

    return ans;
    }
};