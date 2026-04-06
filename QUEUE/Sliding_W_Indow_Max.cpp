class Solution {
    public: //! Tc = O(n) -- deque mein ek hi baar element aata jata hai
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
    
            deque<int> dq; // we are storing idx of element in dq and max element of window will also be at its front
            vector<int> result;// to store max of each window
    
            for(int i = 0; i<n ; i++){
    //Dq shouldnt be empty and dq mein max usi window ke elements mein se hoga so we are popping other elements
                while(!dq.empty() && dq.front() <= i-k){
                    dq.pop_front();
                }
    
                //if new elemt of window > old elem of window stored in DQ pop them 
                while(!dq.empty() && nums[i] > nums[dq.back()]){ // < for sliding window min
                    dq.pop_back();
                }
                
                // and store this max element at front of DQ
                dq.push_back(i);
    
    //window is formed all above ops are over we got max store it in result
                if(i >= k-1){
                    result.push_back(nums[dq.front()]);
                }
            }
            return result;
        }
    };