class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
         // brute force - O(N ^ 3)
         int total = 0;
         int n = nums.size();
         for(int i = 0; i < n ; i++)
         {
            for(int j = i; j < n ; j++)
            {
                int sum = 0;
                for(int k = i ; k <= j; k ++)
                {
                    sum += nums[k];
    
                }
                if(sum % k == 0)
                total++;
            }
         }   
         return total;
        }
    };
//!-----------------------------------------------
class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
         // little optimized  - O(N ^ 2)
         int total = 0;
         int n = nums.size();
         for(int i = 0; i < n ; i++)
         {  
            int sum = 0;
            for(int j = i; j < n ; j++)
            {   sum += nums[j];
                if(sum % k == 0)
                total++;
            }
         }   
         return total;
        }
    };
//!-----------------------------------------------
class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            // optimized approach
            // unordered map 
            unordered_map<int,int>m; // stores remainder of prefix sum by k along with their count
            m[0] = 1; // handles edge case 
    
            int prefixsum = 0 , rem , total = 0; 
            for(int i = 0; i< nums.size() ; i++)
        {
            prefixsum += nums[i];
            rem = prefixsum % k;
    
            if(rem < 0)// if rem is -ve make it +ve
            rem = k + rem;
    
            // if we saw remainder before too then the subarr sum in between is div by k 
            if(m.count(rem))
            {
                total += m[rem];
                m[rem]++;
            }
            else // abhi tak rem nai aya hay 
            m[rem] = 1;
        }
        return total;
        }
    };