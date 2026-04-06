class Solution{
    public:  // TC = O(n! * n) // SC = O(n! +n) = O(n!)
    // helper function
        void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans){

     //! base case
            if(idx == nums.size()){ //base case
                ans.push_back(nums); //pushing our curr permutations in ans
                return;
            }
            for(int i = idx; i<nums.size(); i++){
                //! steps to create unique combinations
                //! swapping in same vec to create new permutation
                swap(nums[idx], nums[i]); // idx(imaginary spaces) ke liye we are taking ith element(orginal element) choice
                getPerms(nums, idx+1, ans); // we are swapping in the same array saving extra SC

                swap(nums[idx], nums[i]); //! backtracking - reverting back swaps before returning them to prev call
            }
        }
vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    getPerms(nums, 0, ans);
    return ans;
}
};  