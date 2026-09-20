#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> findPrimePairs(int n) {
    vector<bool> prime(n + 1, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
      if (prime[i]) {
        for (int j = i * i; j <= n; j += i) {
          prime[j] = false;
        }
      }
    }

    vector<int> primes;

    for (int i = 2; i <= n; i++)
      if (prime[i])
        primes.push_back(i);

    int N = primes.size();

    unordered_map<int, int> m;

    vector<vector<int>> ans;

    for (int i = 0; i < N; i++) {
      m[primes[i]]++;
      int need = n - primes[i];

      if (m.count(need)) {
        ans.push_back({need, primes[i]});
      }
    }

    sort(begin(ans), end(ans));

    return ans;
  }
};