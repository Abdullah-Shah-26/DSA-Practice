class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // Brute force approach - Linear search normal and reverse loop to find 2 occurances from first and last
        //    int start = -1 , end = -1 ;
        // forward loop
        //    for(int i = 0; i < nums.size(); i++)
        //         {
        //             if(nums[i] == target)
        //             {
        //                 start = i;
        //                 break;
        //             }
        //         }
        // reverse loop
        //     for(int i = nums.size() -1 ; i>=0 ; i--)
        //     {
        //         if(nums[i] == target)
        //         {
        //             end = i;
        //             break;
        //         }
        //     }
        //     return {start,end};

        /// ||| -- OPTIMIZED APPROACH _ TC = O(logn)
        // binary search

        int start = 0, end = nums.size() - 1, first = -1, last = -1, mid;

        // first find first occurence of tar
        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                // assume first occurence is mid and search again in left
                first = mid;
                end = mid - 1;
            }
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        // Find last occurence
        start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                // assume last occurence of tar is mid and search again in right
                last = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return {first, last};
    }
};