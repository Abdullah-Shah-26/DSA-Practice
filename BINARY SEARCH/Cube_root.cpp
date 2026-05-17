class Solution
{
public:
    int cubeRoot(int n)
    {
        // code here - brute force - linear search TC = O(N)
        if (n == 0 || n == 1)
            return n;

        for (int i = 2; i <= n; i++)
        {
            // int overflow

            if (i * i >= INT_MAX / i)
                return i - 1;
            else if (i * i * i > n)
                return i - 1;
            else if (i * i * i == n)
                return i;
        }
    }
};
