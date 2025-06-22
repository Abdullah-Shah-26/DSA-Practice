class Solution
{
public:
    int countZeroes(vector<int> &arr)
    {
        // code here
        // brute force _ tc = O(n)
        // int count = 0;
        // for(int i = arr.size()-1 ; i >= 0 ; i--)
        // {
        //     if(arr[i] == 0)
        //     count++;
        // }
        // return count;

        //
        int st = 0, end = arr.size() - 1, mid;

        int first = 0;
        // similar to first occurence problem
        while (st <= end)
        {
            mid = st + (end - st) / 2;

            if (arr[mid] == 1)
            {
                st = mid + 1;
            }
            else if (arr[mid] == 0)
            {
                // store the possible first occurence of 0
                first = mid;
                end = mid - 1;
            }
        }
        end = arr.size() - 1;

        return end - first + 1 == 0 ? 0 : end - first + 1;
    }
};
