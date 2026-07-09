#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio=[](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{for(const auto &x:(a)) cout<<x<<' '; cout<<'\n';}while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define pm(mat) do{for(const auto &r:(mat)){for(const auto &x:(r)) cout<<x<<' '; cout<<'\n';}}while(0)
#define pf(x) cout<<x<<'\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define endl '\n'

/*
==========================

Vitaly calls a positive integer good, if the decimal representation of this integer only contains digits a and b

Vitaly calls a good number excellent, if the sum of its digits is a good number.

==========================
*/

void solve(){
  int a, b, n;
  cin >> a >> b >> n;

  vector<ll> fact(n + 1);
  vector<ll> invFact(n + 1);

  fact[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = (fact[i - 1] * i) % MOD;

  // Fast Power
  auto power = [&](ll base, ll exp) {
    ll ans = 1;

    while (exp > 0) {
      if (exp & 1)
        ans = (ans * base) % MOD;

      base = (base * base) % MOD;
      exp >>= 1;
    }

    return ans;
  };

  invFact[n] = power(fact[n], MOD - 2);

  for (int i = n - 1; i >= 0; i--)
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;

  auto nCr = [&](int N, int R) {
    if (R < 0 || R > N)
      return 0LL;

    return (((fact[N] * invFact[R]) % MOD) * invFact[N - R]) % MOD;
  };

  // Check if a no contains only a and b as digits
  auto isGood = [&](int x){
    if(x == 0)
      return false;

    while(x > 0){
      int digit = x % 10;

      if(digit != a && digit != b)
        return false;

      x /= 10;
    }

    return true;
  };

  ll ans = 0;

  for(int cntA = 0; cntA <= n; cntA++){
    int cntB = n - cntA;
    int sum = cntA * a + cntB * b;
    if(isGood(sum))
      ans = (ans + nCr(n, cntA)) % MOD;
  }

  /*
  why not ans += 1

  113
  131
  311

  so we add nCr(n, cntA)
  Those cnt of a's can be placed at multiple remaining positions & we get the same excellent no
  */

  pf(ans);
}

int main(){

  int t = 1;
/*   cin >> t; */

  while (t--) {
    solve();
  }

  return 0;
}