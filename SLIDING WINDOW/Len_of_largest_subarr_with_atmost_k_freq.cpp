class Solution {
    public:
        int maxSubarrayLength(vector<int>& nums, int k) {
         // brute force approach - TC = O(n^2)
         int Garr = 0;
         int n = nums.size();
         for(int i = 0 ; i < n ; i++)
           {
            // map will store element along with its frequency
            unordered_map<int,int>m;
            vector<int>ans;
            int x ; 
            for(int j = i ; j < n ; j++)
                {
                    m[nums[j]]++;
    
                    if(m[nums[j]] > k)
                    break; 
    
                    ans.push_back(nums[j]);
                    x = ans.size();   
                }
                 Garr = max(x, Garr);
           }
           return Garr;
        }
    };

//!---------------------------------------------------------------
class Solution {
    public:
        int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0 , j = 0 , length = 0;
        unordered_map<int,int>m;
       // sliding window approach - Tc = O(n) = SC
        while(j < n)
        {
            m[nums[j]]++;
        
            while(m[nums[j]] > k && i < n)
            { // decrease window size if freq of no in arr is > k 
                m[nums[i]]--;
                i++;
            }
            length = max(length , j - i + 1);
            j++; // increase window size 
        }
        return length;
        }
    };