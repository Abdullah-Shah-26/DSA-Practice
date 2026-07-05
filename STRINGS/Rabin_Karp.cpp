#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

// Rabin–Karp
class RabinKarp {
private:
  static const ull MOD1 = 1000000007ULL;
  static const ull MOD2 = 1000000009ULL;

  static const ull BASE1 = 313ULL;
  static const ull BASE2 = 317ULL;

public:
  vector<int> find(string &text, string &pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m > n)
      return {};

    vector<int> ans;

    ull pat1 = 0, pat2 = 0;
    ull hash1 = 0, hash2 = 0;
    ull pow1 = 1, pow2 = 1;

    for (int i = 0; i < m; i++) {
      pat1 = (pat1 * BASE1 + pattern[i]) % MOD1;
      pat2 = (pat2 * BASE2 + pattern[i]) % MOD2;

      hash1 = (hash1 * BASE1 + text[i]) % MOD1;
      hash2 = (hash2 * BASE2 + text[i]) % MOD2;

      if (i) {
        pow1 = (pow1 * BASE1) % MOD1;
        pow2 = (pow2 * BASE2) % MOD2;
      }
    }

    ull patHash = (pat2 << 32) | pat1;

    for (int l = 0; l <= n - m; l++) {

      ull textHash = (hash2 << 32) | hash1;

      if (textHash == patHash && text.compare(l, m, pattern) == 0)
        ans.push_back(l);

      if (l == n - m)
        break;

      hash1 =
          ((hash1 + MOD1 - text[l] * pow1 % MOD1) * BASE1 + text[l + m]) % MOD1;
      hash2 =
          ((hash2 + MOD2 - text[l] * pow2 % MOD2) * BASE2 + text[l + m]) % MOD2;
    }

    return ans;
  }
};