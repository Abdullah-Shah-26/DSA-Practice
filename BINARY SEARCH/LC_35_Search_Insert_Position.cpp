class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        //        int maxi = -1;
        //         int ans = 0;
        // // brute force - Linear search
        //         for(int i = 0; i<nums.size();i++)
        //         {
        //             if(nums[i] == target)
        //             {
        //                 ans = i;
        //                 break;
        //             }
        //             if(nums[i] < target)
        //             {
        // //maxi just tracks the largest number less than the target, but you're not doing anything with it
        //                 maxi = max(maxi,nums[i]);
        //                 ans++;
        //             }
        //         }
        //---------Optimizwed - Binary search - TC = O(logn)

        int st = 0, end = nums.size() - 1, idx = nums.size(), mid; // handles edge case where tar correct pos is after last idx
        while (st <= end)
        {
            mid = st + (end - st) / 2;

            if (nums[mid] == target)
            {
                idx = mid;
                break;
            }
            else if (nums[mid] < target) // go right
            {
                st = mid + 1;
            }
            else
            {
                idx = mid;
                end = mid - 1; // tar < mid store idx & go right
            }
        }
        return idx;
    }
};