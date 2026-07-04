#include <bits/stdc++.h>
using namespace std;

// TC = O(N * M * K)

using ll = long long;
const ll NEG = -(1LL << 60);

class Solution {
public:
  int n, m, k;
  ll dp[101][101][101];

  ll f(int i, int j, vector<int> &nums1, vector<int> &nums2, int t) {
    if (t == k) // No more pairs needed
      return 0;

    if (i == n || j == m)
      if (t < k) // Cannot form further pairs
        return NEG;
      else
        return 0;

    ll need = k - t;
    if (need > n - i || need > m - j) // Dont have enough i,j to form future pairs
      return NEG;

    if (dp[i][j][t] != NEG)
      return dp[i][j][t];

    ll ans = NEG;

    ll skipI = f(i + 1, j, nums1, nums2, t);
    ll skipJ = f(i, j + 1, nums1, nums2, t);
    ll takeIJ = 1LL * nums1[i] * nums2[j] + f(i + 1, j + 1, nums1, nums2, t + 1);

    ans = max({ans, skipI, skipJ, takeIJ});

    return dp[i][j][t] = ans;
  }

  long long maxScore(vector<int> &nums1, vector<int> &nums2, int K) {
    n = nums1.size();
    m = nums2.size();
    k = K;

    // -1 cannot be used as sentinel cause it can be a valid ans here
    fill(&dp[0][0][0], &dp[0][0][0] + 101 * 101 * 101, NEG);

    return f(0, 0, nums1, nums2, 0);
  }
};