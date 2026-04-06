class Solution
{
public:
    int mySqrt(int x)
    {
        // Binary search - Optimized approach - OLogn
        int start = 0, end = x, mid, ans;
        // edge case
        if (x == 0 || x == 1)
            return x;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (mid == x / mid) // edge case int overflow
            {
                ans = mid;
                break;
            }

            else if (mid < x / mid)
            { // store the mid because it can be probable ans and go right
                ans = mid;
                start = mid + 1;
            }
            else
            { // mid * mid > tar  - Go left
                end = mid - 1;
            }
        }
        return ans;
    }
};