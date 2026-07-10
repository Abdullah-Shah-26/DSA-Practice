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

extendedGCD(a, b, x, y)

Returns:
g = gcd(a, b)

Also computes x and y such that

a*x + b*y = g

Extended GCD is the standard algorithm for solving linear Diophantine eq with 2 variables.

==========================
*/

ll extendedGCD(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    // a(1) + 0(0) = a = gcd(a,0)
    x = 1;
    y = 0;
    return a;
  }

  ll x1, y1;
  ll gcd = extendedGCD(b, a % b, x1, y1);

  x = y1;
  y = x1 - (a / b) * y1;

  return gcd;
}

int main() {
  ll a = 30, b = 18; // a,b = fixed
  ll x, y; 

  ll g = extendedGCD(a, b, x, y);

  cout << "gcd = " << g << '\n';
  cout << "x = " << x << '\n';
  cout << "y = " << y << '\n';
  cout << a * x + b * y << '\n';
}