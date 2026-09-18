#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int N = 100005;

class Solution {
public:
  ll binExpo(ll a, ll b) {
    ll ans = 1;

    while (b) {
      if (b & 1)
        ans = (ans * a) % MOD;

      a = a * a % MOD;
      b >>= 1;
    }

    return ans;
  }

  int countAnagrams(string word) {
    static bool pre = false;
    static vector<ll> fact(N, 1), invFact(N, 1);

    if (!pre) {
      pre = true;

      fact[0] = 1;
      for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

      invFact[N - 1] = binExpo(fact[N - 1], MOD - 2);
      for (int i = N - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    vector<string> s;

    stringstream ss(word);

    string w;

    while (ss >> w)
      s.push_back(w);

    int ans = 1;
    vector<int> freq(26, 0);

    for (auto x : s) {
      ans = (ans * fact[x.size()]) % MOD;

      for (auto ch : x)
        freq[ch - 'a']++;

      for (auto i : freq)
        ans = (ans * invFact[i]) % MOD;

      fill(freq.begin(), freq.end(), 0);
    }

    return ans;
  }
};