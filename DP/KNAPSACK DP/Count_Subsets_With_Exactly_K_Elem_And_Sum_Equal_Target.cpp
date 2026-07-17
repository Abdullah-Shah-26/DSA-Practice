#include <bits/stdc++.h>
using namespace std;

int w, n, x;
vector<int> wt;
int dp[101][51][201];

int solve(int i, int taken, int sum) {
  if (taken == n)
    return sum == w;

  if (i == x)
    return 0;

  if (sum > w || taken > n)
    return 0;

  if (dp[i][taken][sum] != -1)
    return dp[i][taken][sum];

  int skip = solve(i + 1, taken, sum);
  int take = solve(i + 1, taken + 1, sum + wt[i]);

  return dp[i][taken][sum] = take + skip;
}

int main() {
  cin >> w; // Target sum

  // N = no of snacks to be chosen
  cin >> n >> x;

  wt.assign(x, 0);

  for (int i = 0; i < x; i++) {
    cin >> wt[i];
  }

  memset(dp, -1, sizeof(dp));

  cout << solve(0, 0, 0);
}