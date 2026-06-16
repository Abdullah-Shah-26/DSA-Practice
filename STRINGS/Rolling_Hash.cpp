#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

// Double polynomial rolling hash
class StringHash{
private : 
  static const ull MOD1 = 1000000007ULL;
  static const ull MOD2 = 1000000009ULL;
  static const ull BASE1 = 313ull;
  static const ull BASE2 = 317ull;

  vector<ull> pref1;
  vector<ull> pref2;

  vector<ull> pow1;
  vector<ull> pow2;
  
public:
  StringHash(vector<int> &s){
    int n = s.size();
    
    pref1.assign(n + 1, 0);
    pref2.assign(n + 1, 0);

    pow1.assign(n + 1, 1);
    pow2.assign(n + 1, 1);

    for(int i = 0; i < n; i++){
      pow1[i + 1] = (pow1[i] * BASE1) % MOD1;
      pow2[i + 1] = (pow2[i] * BASE2) % MOD2;

      // +1 to avoid 0
      pref1[i + 1] = (pref1[i] * BASE1 + s[i] + 1) % MOD1;
      pref2[i + 1] = (pref2[i] * BASE2 + s[i] + 1) % MOD2;
    }
  }

  ull getHash(int l, int r){
    ull h1 = (pref1[r + 1] + MOD1 - pref1[l] * pow1[r - l + 1] % MOD1) % MOD1;
    ull h2 = (pref2[r + 1] + MOD2 - pref2[l] * pow2[r - l + 1] % MOD2) % MOD2;

    return (h2 << 32) | h1;
  }

  bool equal(int l1, int r1, int l2, int r2){
    return getHash(l1, r1) == getHash(l2, r2);
  }
};