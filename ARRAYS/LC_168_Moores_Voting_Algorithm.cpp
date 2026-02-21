class Solution {  //? Majority Element
    public: //! MOORES VOTING ALGORITHM _ TC = (N)  
        int majorityElement(vector<int>& nums) {
           // freq is like votes or power  
           int freq = 0, ans = 0;
    
            for (int i=0; i<nums.size() ;i++){
                if (freq==0){//freq is 0 ans becomes that value
                    ans =nums[i];
                }
                if (ans ==nums[i]){//if element is same increase frequency
                    freq++;
                }else{
                    freq--;//if element is different decrease frequency even then the majority element will have highest freq at the end 
                }
            } return ans;
        }
       
    };