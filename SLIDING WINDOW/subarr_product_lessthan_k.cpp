class Solution {
    public: // TC = O(n^2)
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            int n = nums.size();
            int total = 0;
            for(int i = 0; i < n; i++){
                long long product = 1; 
                for(int j = i ; j < n; j++)
                {
                    if(product < INT_MAX)
                    product *= nums[j];
                    if(product < k )
                    total++;
                }
            }
            return total;
        }
    };
 //!________________________
 class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // sliding window approach - TC = O(n)
        int product = 1, start = 0, end = 0, n = nums.size();
        int count = 0;
        while(end < n)
        {
            product *= nums[end];
    
            while(product >= k && start <= end) // product exceed k then decrease window size from front 
            {
                product /= nums[start];
                start++;
            }
            // else increase window size 
            count += end - start + 1; // the no of subarrays = size since if whole sub arr product is less than k then individual and subof sub array ka product will also be < k
            end++;
        }
    return count;
        }
    };
