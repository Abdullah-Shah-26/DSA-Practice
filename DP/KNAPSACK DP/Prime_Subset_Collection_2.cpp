#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
  bool isPrime(int x) {
    if (x < 2)
      return false;

    for (int i = 2; i * i <= x; i++)
      if (x % i == 0)
        return false;

    return true;
  }

  // Min no of primes req to make this target sum
  // If we can't make return INF
  int dp[200][1001];
  int minPrimes(int i, vector<int> &primes, int target) {
    if (target == 0)
      return 0;

    if (i == primes.size())
      return INF;

    if (dp[i][target] != -1)
      return dp[i][target];

    // Skip
    int ans = minPrimes(i + 1, primes, target);

    // Take
    if (primes[i] <= target) {
      int next = minPrimes(i + 1, primes, target - primes[i]);

      if (next != INF)
        ans = min(ans, 1 + next);
    }

    return dp[i][target] = ans;
  }

  vector<int> maxPrimeSubset(int n, int s) {
    vector<int> primes;

    for (int x = 2; x <= n; x++)
      if (isPrime(x))
        primes.push_back(x);

    memset(dp, -1, sizeof(dp));

    // Finding the largest sum we can make using primes from 1 -> n
    // Also it counts the min no of primes we need to make that sum
    int target = 0;
    int minCnt = 0;

    for (int sum = s; sum > 0; sum--) {
      int cnt = minPrimes(0, primes, sum);

      if (cnt != INF) {
        target = sum;
        minCnt = cnt;
        break;
      }
    }

    int remSum = target;
    int remCnt = minCnt;

    vector<int> ans;

    // We can use this prime in ans only if remaining elements can form remSum
    for (int i = 0; i < primes.size(); i++) {
      if (remSum >= primes[i] &&
          minPrimes(i + 1, primes, remSum - primes[i]) == remCnt - 1) {
        ans.push_back(primes[i]);
        remSum -= primes[i];
        remCnt -= 1;
      }
    }

    return ans;
  }
};