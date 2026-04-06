class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
    //! Brute force approach -  TC = O(N^2)
             if (nums.empty()) return 0;
    
          
          int maxelem = *max_element(nums.begin(), nums.end());
    
            int count =  0;
            for(int i = 0 ; i < n ; i ++)
            {
                int maxcount = 0; 
                for(int j = i ; j < n ; j++)
                {
                    if(nums[j] == maxelem) // count the no of times max elem is occuring in each subarray 
                    maxcount++;
    
    // if its a valid subarray increase it count 
                    if(maxcount >= k)
                    count++;
                }
            }
            return count;
        }
    };
///!___________________________________________________________________________________
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
          // sliding window approach - tc = o(n) sc = O(1)
           int maxelem = 0 , n = nums.size();
    
           for(int i = 0 ; i < n ; i ++)
            maxelem = max(maxelem, nums[i]);
    
        long long total = 0;// stores the no of valid subarrays 
        int count = 0, start = 0 , end = 0; 
         
         while(end < n ){
            if(nums[end] == maxelem) 
            count++;// freq of maxlem in subarr
    
            // window length kab tak increase karni hay 
            // until freq of maxelem is subarray becomes equal to k 
            while(count == k)
            {
                total += n - end; // adding all the valid subarrays
                // decrease the window size & if first elem of window is maxelem dec its freq too
                if(nums[start] == maxelem)
                count--;
    
                start++;
            }
            end++;
         }
         return total;
        
        }
    };