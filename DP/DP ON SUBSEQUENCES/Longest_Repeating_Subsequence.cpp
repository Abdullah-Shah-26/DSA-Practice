#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution
{
public:
    // TC =  O(N^2) // SC = O(N)
    // Can be further Optimized To 1D row & store prevDiag
    int LongestRepeatingSubsequence(string &s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // LCS + i != j Condition
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == s[j - 1] && i != j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
};

/*


      0  1  2  3  4  5  6
      a  b  a  c  b  c  -

0 a   3  3  3  1  1  1  0

1 b   3  2  2  2  2  1  0

2 a   3  2  1  1  1  1  0

3 c   2  2  1  1  1  1  0

4 b   2  2  1  1  0  0  0

5 c   1  1  1  1  0  0  0

6 -   0  0  0  0  0  0  0

*/