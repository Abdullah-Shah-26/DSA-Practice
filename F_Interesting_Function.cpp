#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

// ---------- GCD / LCM ----------
int gcdInt(int a,int b){ while(b){ a%=b; swap(a,b);} return a; }
int lcmInt(int a,int b){ return a/gcdInt(a,b)*b; }
ll gcdll(ll a,ll b){ while(b){ a%=b; swap(a,b);} return a; }
ll lcmll(ll a,ll b){ return a/gcdll(a,b)*b; }

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
ll modAdd(ll a,ll b,ll m=MOD){ return (a%m+b%m)%m; }
ll modSub(ll a,ll b,ll m=MOD){ return (a%m-b%m+m)%m; }
ll modMul(ll a,ll b,ll m=MOD){ return (a%m*b%m)%m; }

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

// ---------- Prefix sum ----------
vector<ll> prefixSum(const vector<ll>& a){
    int n=a.size();
    vector<ll> pref(n+1,0);
    for(int i=0;i<n;i++) pref[i+1]=pref[i]+a[i];
    return pref;
}

// ---------- Newline helper ----------
inline void nl(){ cout << '\n'; }

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)

// ll f(ll x){
//   ll res = 0;

//   while(x > 0){
//     res += x;
//     x/= 10;
//   }

//   return res;
// }

// ---------- Solve ---------
void solve(){
    ll l,r;
    cin >> l >> r;
    ll cnt = 0;

    while(r > 0){
      cnt += (r - l);
      r/=10;
      l/=10;
    }

    cout << cnt << endl;
}

// ---------- Main ----------
int main(){
    int t; 
    cin>>t;
    while(t--)
    solve();
    return 0;
}