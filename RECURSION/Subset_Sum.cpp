#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int idx, int n, int sum, vector<int> &ans)
{
    // base case
    if (idx == n)
    {
        ans.push_back(sum); // store the current sum
        return;
    }

    // include the current element
    print(arr, idx + 1, n, sum + arr[idx], ans);

    // exclude the current element
    print(arr, idx + 1, n, sum, ans);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> ans;
    print(arr, 0, 4, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  "; // print each subset sum
    }
}


class Solution {
  public:
   
    bool isSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        // Bottom Up approach
        vector<vector<bool>>dp(n, vector<bool>(k + 1, 0));
        
        for(int i = 0; i < n; i++)
        dp[i][0] = true;
        
        dp[0][arr[0]] = true;
        
        for(int idx = 1; idx < n ; idx++)
        {
            for(int target = 1; target <= k ; target++)
            {
                bool notTake = dp[idx -1][target];
                bool take = false;
                
                if(arr[idx] <= target)
                take = dp[idx-1][target - arr[idx]];
            dp[idx][target] = take || notTake;
                
            }
        }
        return dp[n-1][k];
    }
};


class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<bool> prev(k + 1, false), curr(k + 1, false);

        prev[0] = true;  // base case: empty subset sums to 0

        if (arr[0] <= k)
            prev[arr[0]] = true;  // handle first element safely
        
        for (int idx = 1; idx < n; idx++) {
            fill(curr.begin(), curr.end(), false);  // reset curr for each iteration
            for (int target = 0; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                
                if (arr[idx] <= target)
                    take = prev[target - arr[idx]];

                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[k];  // ✅ Final answer
    }
};