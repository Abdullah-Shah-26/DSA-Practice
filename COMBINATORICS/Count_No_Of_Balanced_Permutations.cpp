#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int n;
  ll totalSum;
  ll totalPerms;

  vector<vector<vector<ll>>> dp;

  ll binExpo(ll a, ll b) {
    ll ans = 1;

    while (b) {
      if (b & 1)
        ans = (ans * a) % MOD;

      a = (a * a) % MOD;
      b >>= 1;
    }

    return ans;
  }

  ll solve(int digit, int evenIdxDigitCnt, ll evenIdxSum, vector<int> &freq,
           vector<ll> &invFact) {

    int targetCnt = (n + 1) / 2;
    ll targetSum = totalSum / 2;

    // Pruning
    if (evenIdxDigitCnt > targetCnt)
      return 0;

    if (evenIdxSum > targetSum)
      return 0;

    // All digits processed
    if (digit == 10) {
      if (evenIdxDigitCnt == targetCnt && evenIdxSum == targetSum)
        return totalPerms;

      return 0;
    }

    ll &ans = dp[digit][evenIdxDigitCnt][evenIdxSum];

    if (ans != -1)
      return ans;

    ans = 0;

    // How many copies of this digit can go into even positions?
    int maxCnt = min(freq[digit], targetCnt - evenIdxDigitCnt);

    for (int cnt = 0; cnt <= maxCnt; cnt++) {

      int evenPosCnt = cnt;
      int oddPosCnt = freq[digit] - cnt;

      ll ways = (invFact[evenPosCnt] * invFact[oddPosCnt]) % MOD;

      ll val = solve(digit + 1, evenIdxDigitCnt + evenPosCnt,
                     evenIdxSum + 1LL * digit * cnt, freq, invFact);

      ans = (ans + val * ways) % MOD;
    }

    return ans;
  }

  int countBalancedPermutations(string nums) {
    n = nums.size();
    totalSum = 0;

    vector<int> freq(10, 0);

    for (char c : nums) {
      int digit = c - '0';

      totalSum += digit;
      freq[digit]++;
    }

    // Total sum must be even
    if (totalSum & 1)
      return 0;

    int evenCnt = (n + 1) / 2;
    int oddCnt = n / 2;

    // Factorials
    vector<ll> fact(n + 1, 1);

    for (int i = 2; i <= n; i++)
      fact[i] = fact[i - 1] * i % MOD;

    // Inverse factorials
    vector<ll> invFact(n + 1, 1);

    invFact[n] = binExpo(fact[n], MOD - 2);

    for (int i = n - 1; i >= 0; i--)
      invFact[i] = invFact[i + 1] * (i + 1) % MOD;

    // Number of ways to arrange selected digits
    // in even positions and odd positions.
    totalPerms = fact[evenCnt] * fact[oddCnt] % MOD;

    /*
      dp[digit][evenIdxDigitCnt][evenIdxSum]

      digit             -> which digit we're processing
      evenIdxDigitCnt   -> how many digits placed in even positions
      evenIdxSum        -> their current sum
    */
    dp.assign(
        10, vector<vector<ll>>(evenCnt + 1, vector<ll>(totalSum / 2 + 1, -1)));

    return solve(0, 0, 0, freq, invFact);
  }
};