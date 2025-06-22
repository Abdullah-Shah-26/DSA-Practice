class Solution
{ // or we can just use STL fun nextpermutation( A.begin(), A.end() ); ->aint allowed in interviews
public:
    void nextPermutation(vector<int> &A)
    { // TC = O(n) && SC = O(1)
        // 1. Find pivot
        int pivot = -1;
        int n = A.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i] < A[i + 1])
            {
                pivot = i;
                break;
            }
        }
        // if pivot doesnt exist
        if (pivot == -1)
        {
            reverse(A.begin(), A.end()); // in place changes (without using extra space)
            return;
        }

        // 2nd step : find right most element just > pivot by using backward loop since elements are arranged in descending order
        for (int i = n - 1; i > pivot; i--)
        {
            if (A[i] > A[pivot])
            {
                swap(A[i], A[pivot]);
                break;
            }
        }
        // 3rd step: reverse (piv +1 to n-1)

        // reverse(A.begin() + pivot + 1 , A.end());

        // 2 pointer approach
        int i = pivot + 1, j = n - 1;
        while (i <= j)
        {
            swap(A[i++], A[j--]);
        }
    }
};
