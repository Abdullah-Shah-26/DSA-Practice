class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // brute force approach - tc = O(n)

        int num = 1;

        int n = arr.size();
        int i = 0;

        while (i < n && k > 0)
        {
            if (arr[i] == num)
            { // not missing that no
                i++;
            }
            else
            { // missing that no
                k--;
            }
            num++;
        }

        // edge case where missing no comes after array ends
        while (k--)
        {
            num++;
        }
        return num - 1; // since even if k = 0 num gets incremented once in both loops
    }
};