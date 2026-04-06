class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
//! brute force - TC = O(n^2)
            int count = 0;
            int n = nums.size();
    
            for(int i = 0; i < n ; i++)
            {
                long long int score = 1 , sum = 0;
                for(int j = i ; j < n ; j++)
                {
                    sum += nums[j];
                    score = j - i + 1;
                    score *= sum;
    
                    if(score < k)
                    count++;
                }
            }
            return count;
        }
    };

//! optimized approach 
class Solution {
    public:
    // sliding window _ TC = O(N^2) SC = O(1)
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();
    // score = sum * size of subarr
            long long sum = 0, score = 0, count = 0;
    
            int start = 0, end = 0 ;
            while(end < n)
            {
                sum += nums[end];
                score = sum * (end - start + 1);
    // decrease the window size until score becomes valid ie < k
                while(score >= k && start <= end)
                {
                    sum -= nums[start];
                    start++;
                    score = sum * (end - start + 1);
                }
                count+= (end - start + 1);
                end++; // until score is valid increase the window size
            }
            return count;
        }
    };
