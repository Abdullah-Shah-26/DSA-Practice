class Solution {
    public:
        int minKBitFlips(vector<int>& nums, int k) {
            class Solution {
    public:
        int minKBitFlips(vector<int>& nums, int k) {
            //! Brute force  TC = O(nk) SC = O(1) - TLE 
            int flip = 0;
            int n = nums.size();
    
            for(int i =0; i<n; i++){
                if(nums[i] == 0){
                    // base cond - window doesnt exist
                    if(i + k -1 >= n)
                    return -1; // cannot make all bits 0
    
                    //finding window
                    for(int j = i; j<= i+k-1; j++)
                    {
                        nums[j] =! nums[j]; // flipping bits
                    }
                    flip++;
                }
            }
            return flip;
    
        }
    };
//!----------------------------------------------------------------------------------------------------------------------------
class Solution {
    public: //! TC = O(n)  // SC = O(1)
        int minKBitFlips(vector<int>& nums, int k) {
           //! optimized approach 
           queue<int> q;
           int flip = 0;
           int n = nums.size();
    
           for(int i = 0; i<n; i++){
    
            // q shouldnt be empty and q ka front < idx hay pop it
                if(!q.empty() && q.front() < i)
                q.pop();
    
                // condition to flip the bit 
                if(q.size()%2 == nums[i]){
    
                    //first check if window is forming
                    if(i+k-1 >= n)
                    return -1;
    
                    // if it is then push the index jaha tak pop karna hay in q
                    q.push(i+k-1);
                    flip++; // and increase flip
                }
    
           }
           return flip;
        }
    };