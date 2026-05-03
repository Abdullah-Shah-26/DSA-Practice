#include <bits/stdc++.h>
using namespace std;

/*
LONGEST INCREASING SUBSEQUENCE (LIS) - ALL APPROACHES

1) Pure Recursion -> O(2^n)
2) Memoization (Top Down) -> O(n^2)
3) Bottom Up DP -> O(n^2)
4) Space Optimized DP -> O(n^2)
5) Patience Sorting -> O(n log n)
 
*/

// 1. PURE RECURSION

int lisRec(int i, int prevIdx, vector<int>& a, int n) {
    if (i == n) return 0;

    int skip = lisRec(i + 1, prevIdx, a, n);

    int take = 0;
    if (prevIdx == -1 || a[i] > a[prevIdx])
        take = 1 + lisRec(i + 1, i, a, n);

    return max(take, skip);
}

// 2. MEMOIZATION (TOP DOWN)

int lisMemo(int i, int prevIdx, vector<int>& a, int n,
            vector<vector<int>>& dp) {

    if (i == n) return 0;

    if (dp[i][prevIdx + 1] != -1)
        return dp[i][prevIdx + 1];

    int skip = lisMemo(i + 1, prevIdx, a, n, dp);

    int take = 0;
    if (prevIdx == -1 || a[i] > a[prevIdx])
        take = 1 + lisMemo(i + 1, i, a, n, dp);

    return dp[i][prevIdx + 1] = max(take, skip);
}

// 3. BOTTOM UP DP O(n^2)
// dp[i] = LIS ending at i

int lisTab(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

// 5. PATIENCE SORTING O(n log n)
//* Does Not preserve original indices ordering = so cannot 

int lisOptimal(vector<int>& a) {
    vector<int> tails;

    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);

        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }

    return tails.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    // 1) Pure Recursion (small n only)
    cout << "Recursion: " << lisRec(0, -1, a, n) << '\n';

    // 2) Memoization
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << "Memoization: " << lisMemo(0, -1, a, n, dp) << '\n';

    // 3) Bottom Up
    cout << "Bottom Up: " << lisTab(a) << '\n';

    // 4) Space Optimized
    cout << "Space Optimized: " << lisSpace(a) << '\n';

    // 5) Optimal
    cout << "Patience Sorting: " << lisOptimal(a) << '\n';

    return 0;
}