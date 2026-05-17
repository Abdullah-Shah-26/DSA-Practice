class Solution {
  public:
    vector<int> candyStore(int candies[], int N, int k) {
        // Write Your Code here
        int min_amt = 0, max_amt = 0;
        int i = 0 , j = N - 1;
        sort(candies, candies
        + N);
        // For min amount 
        while(i <= j)
        {
            min_amt += candies[i];
            i++;
            j -= k;
        }
        i = N-1, j = 0;
        
        // For  max amount 
        while(i >= j)
        {
            max_amt += candies[i];
            i--;
            j += k;
        }
        vector<int>ans;
        ans.push_back(min_amt);
        ans.push_back(max_amt);
        
        
        return ans;
    }
};