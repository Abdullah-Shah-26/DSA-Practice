class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // code here
        // brute force - linear search tc= O(n)
        // int total = 0;
        // for(int i = 0 ; i < arr.size() ; i++)
        // {
        //     if(arr[i] == target)
        //     total++;
        // }
        // return total;

        // Binary search apporach - Tc = O(logn)
        // find first occurence

        int st = 0, end = arr.size() - 1, first = -1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (arr[mid] == target)
            {
                first = mid;
                // and go left
                end = mid - 1;
            }
            else if (arr[mid] < target)
            {
                st = mid + 1;
            }
            else
                end = mid - 1;
        }
        // target not found
        if (first == -1)
            return 0;

        // find last occurence of target
        st = 0, end = arr.size() - 1;
        int last = -1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (arr[mid] == target)
            {
                last = mid;
                // and go right
                st = mid + 1;
            }
            else if (arr[mid] < target)
            {
                st = mid + 1;
            }
            else
                end = mid - 1;
        }

        return last - first + 1;
    }
};