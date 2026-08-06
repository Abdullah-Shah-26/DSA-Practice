#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

class RollingHash {
private:
  const ull MOD1 = 1000000007ULL;
  const ull MOD2 = 1000000009ULL;
  const ull BASE1 = 313ULL;
  const ull BASE2 = 317ULL;

  vector<ull> pref1, pref2;
  vector<ull> pow1, pow2;

public:
  RollingHash(string &s) {
    int n = s.size();

    pref1.assign(n + 1, 0);
    pref2.assign(n + 1, 0);

    pow1.assign(n + 1, 1);
    pow2.assign(n + 1, 1);

    for (int i = 0; i < n; i++) {
      pow1[i + 1] = (pow1[i] * BASE1) % MOD1;
      pow2[i + 1] = (pow2[i] * BASE2) % MOD2;

      pref1[i + 1] = (pref1[i] * BASE1 + (s[i] - 'a' + 1)) % MOD1;
      pref2[i + 1] = (pref2[i] * BASE2 + (s[i] - 'a' + 1)) % MOD2;
    }
  }

  ull getHash(int l, int r) {
    ull h1 = (pref1[r + 1] - pref1[l] * pow1[r - l + 1] % MOD1 + MOD1) % MOD1;
    ull h2 = (pref2[r + 1] - pref2[l] * pow2[r - l + 1] % MOD2 + MOD2) % MOD2;

    return (h2 << 32) | h1;
  }

  bool equal(int l1, int r1, int l2, int r2) {
    return getHash(l1, r1) == getHash(l2, r2);
  }
};

class Solution {
public:
  int check(int len, string &s) {
    int n = s.size();

    RollingHash hash(s);

    unordered_set<ull> seen;

    for (int i = 0; i + len <= n; i++) {
      ull h = hash.getHash(i, i + len - 1);

      if (seen.count(h)) {
        return i;
      }

      seen.insert(h);
    }

    return -1;
  }

  string longestDupSubstring(string s) {
    int n = s.size();
    int low = 1, high = n - 1;
    int idx = -1, maxLen = 0, stIdx = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      idx = check(mid, s);

      if (idx != -1) {
        stIdx = idx;
        maxLen = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    if (stIdx == -1)
      return "";

    return s.substr(stIdx, maxLen);
  }
};