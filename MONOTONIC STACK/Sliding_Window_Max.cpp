#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    vector<int>ans     ;
    deque<int>dq;
   for(int i = 0;i < n;i++)
   {
       // dq - back - is acting as stack
       // if idx doenst belong to this window
       //0   1  2   3  4 || k = 2
       //11 |12 13| 14 15
       //       i
       if(!dq.empty() && dq.front() <= i-k) dq.pop_front();
       while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
       dq.push_back(i);
       // window started
       if(i>=k-1) ans.push_back(nums[dq.front()]);
   }
    return ans;
}