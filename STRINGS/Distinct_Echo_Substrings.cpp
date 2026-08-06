#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

class RollingHash {
private:
  const ull BASE = 131;
  const ull MOD = 1e9 + 7;

  vector<ull> pref;
  vector<ull> power;

public:
  RollingHash(string &s) {
    int n = s.size();

    pref.resize(n + 1, 0);
    power.resize(n + 1);
    power[0] = 1;

    for (int i = 1; i <= n; i++)
      power[i] = power[i - 1] * BASE % MOD;

    for (int i = 0; i < n; i++)
      pref[i + 1] = (pref[i] * BASE + (s[i] - 'a' + 1)) % MOD;
  }

  // [l...r] Both indices inclusive
  ull getHash(int l, int r) {
    ull hash = (pref[r + 1] - pref[l] * power[r - l + 1] % MOD + MOD) % MOD;

    return hash;
  }
};

class Solution {
public:
  int distinctEchoSubstrings(string text) {
    int n = text.size();

    RollingHash hash(text);

    unordered_set<ull> seen;

    for (int st = 0; st < n; st++)
      for (int half = 1; st + 2 * half <= n; half++)
        if (hash.getHash(st, st + half - 1) == hash.getHash(st + half, st + 2 * half - 1))
          seen.insert(hash.getHash(st, st + 2 * half - 1));

    return seen.size();
  }
};