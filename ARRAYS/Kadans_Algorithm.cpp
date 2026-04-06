//! TO CALCULATE MAX SUB ARRAY SUM - KADANS ALGORITHM - TC = O(N) - SINGLE LOOP 
class Solution {  //! SC = O(1)
    public:
        int maxSubArray(vector<int>& nums) {
            int currSum = 0 , maxSum = 0;

            for(int val : nums){
                currSum += val;
                maxSum = max(currSum, maxSum);
                if(currSum < 0){ //since if subarr sum is -ve reset it to 0 beacuse -ve values will further decrease currSum
                    currSum = 0;
                }
            }
            return maxSum;
        }
};