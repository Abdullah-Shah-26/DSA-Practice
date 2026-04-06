class Solution {
public:
void permut(vector<int> &arr, vector<vector<int>> &ans, int idx)
{   
    // base case 
    if(idx == arr.size())
    {
        ans.push_back(arr);
        return;
    }


    // array to track the used elements
    vector<bool>use(21, 0);
    for(int i = idx ; i < arr.size(); i++)
    {
        // can use if its coming first time 
        if(use[arr[i] + 10] == 0)
        {
            swap(arr[i], arr[idx]);
            permut(arr, ans, idx + 1);

            // while returning swap them back to same position
            swap(arr[i], arr[idx]);
            use[arr[i] + 10] = 1; 
        }
    }
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;

        permut(nums, ans, 0);
        return ans;
    }
};