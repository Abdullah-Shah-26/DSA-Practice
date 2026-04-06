// subset cannot contain duplicate element arr = {1,2,2}                                                                                                
class Solution{   // TC = O(nlogn(due to sorting) + 2^n * n) = O(n * 2^n)
    public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i ,vector<vector<int>> &allSubsets){
        if(i == nums.size()){//base case
            allSubsets.push_back(ans); // to print all subsets
            return;
        }

        //include an element in subset
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);

        //BackTracking removing the elements and returning org subset to prev call before excluding step
        ans.pop_back();

        int idx = i+1; //to skip the repeating elements before excluding else we will get repeated subsets
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        // excluding an element in subset
        getAllSubsets(nums, ans, idx, allSubsets);
    }



    vector<vector<int>> allSubsets(vector<int> &nums){
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets); // calling the subset func
        return allSubsets;
    }
};