#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int N = 100000;

vector<ll> fact(N + 1);
vector<ll> invFact(N + 1);

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1)
      ans = ans * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return ans;
}

void precompute(){
  fact[0] = 1; 

  for(int i = 1; i <= N; i++)
    fact[i] = fact[i - 1] * i % MOD;

  // Fermat's Little Theorem
  invFact[N] = binExpo(fact[N], MOD - 2);

  for(int i = N - 1; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll nCr(int n, int r){
  if(r < 0 || r > n)
    return 0;

  return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main(){
  precompute();

  cout << nCr(5,2) << endl;
  cout << nCr(10,3) << endl;
  cout << nCr(1000,500) << endl;

  return 0; 
}