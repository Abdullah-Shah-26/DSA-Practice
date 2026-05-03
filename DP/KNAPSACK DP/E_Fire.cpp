#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- Modular arithmetic ----------
ll modPow(ll a,ll b,ll m=MOD){
    ll res=1;
    while(b){
        if(b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
ll modInv(ll a,ll m=MOD){ return modPow(a,m-2,m); }

// ---------- Bit helpers ----------
int bitCount(ll x){ return __builtin_popcountll(x); }
int msbIndex(ll x){ return 63-__builtin_clzll(x); }
int lsbIndex(ll x){ return __builtin_ctzll(x); }

// ---------- Divisors ----------
vector<ll> getDivisors(ll n){
    vector<ll> d;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(i*i!=n) d.push_back(n/i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

// ---------- Primes (Sieve) ----------
// Usage: vector<int> spf; auto primes = linearSieve(N, spf);
// spf[x] = smallest prime factor of x (for x>=2)
vector<int> linearSieve(int n, vector<int>& spf){
    spf.assign(n+1, 0);
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(spf[i]==0){ spf[i]=i; primes.push_back(i); }
        for(int p: primes){
            if(p>spf[i] || 1LL*i*p>n) break;
            spf[i*p]=p;
        }
    }
    return primes;
}
bool isPrimeSieve(int x, const vector<int>& spf){
    return x>=2 && x<(int)spf.size() && spf[x]==x;
}

// ---------- Primality (sqrt) ----------
bool isPrime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{ for(const auto &x:(a)) cout<<x<<' '; cout<<'\n'; }while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define nl do{ cout << '\n'; }while(0)

int n;

int dfs(int i, int curTime, vvi &a, vvi &dp){
  if(i == n) return 0;

  if(dp[i][curTime] != -1)
    return dp[i][curTime];

  int skip = dfs(i + 1, curTime, a, dp);

  int d = a[i][0]; // deadline
  int t = a[i][1]; // duration - time needed to save
  int p = a[i][2]; // profit

  int take = 0;

  if(curTime + t < d){
    take = p + dfs(i + 1, curTime + t, a, dp);
  }

  return dp[i][curTime] = max(skip, take);
}

// ---------- Solve ---------
void solve(){
  cin >> n;

  vvi a(n, vi(4,0)); // deadline, time, value, originalIdx

  for(int i = 0; i < n; i++){
    int deadline, time, value;

    cin >> time >> deadline >> value;

    a[i] = {deadline, time, value, i+1};
  }

  sort(all(a));

  vvi dp(n, vi(2001, -1)); // idx, time

  int best = dfs(0, 0, a, dp);

  vi path;

  int i = 0, curTime = 0;

  while(i < n){
    int skip = dfs(i + 1, curTime, a, dp);

    int d = a[i][0]; // deadline
    int t = a[i][1]; // duration - time needed to save
    int p = a[i][2]; // value of item
    int idx = a[i][3];

    int take = -1;

    if(curTime + t < d){
      take = p + dfs(i + 1, curTime + t, a, dp);
    }

    if(take >= skip){
      path.push_back(idx);
      curTime += t;
    }

    i++;
  }

  cout << best << endl;
  cout << path.size() << endl;

  pv(path);

  return;
}

// ---------- Main ----------
int main(){

    solve();
    return 0;
}