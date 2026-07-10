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

// TODO : 

/*
==========================

Gap Len 1 : 101 -> 111
    Len 2 : 1001 ->
             AB
    AB 
    BA 
    2 ways

    Len 3 : 10001
             ABC
    ABC
    ACB
    CBA
    CAB
    4 ways

    Len L = 2^(L-1)


Interleaving : 

1 0 0 1 0 0 1
1 A B 1 C D 1

Gap 1: A B
Gap 2: C D

Can do 
ABCD
CDAB
ACBD
CADB

Counting Trick : 

Assuming internal order is fixed
A before B
C before D

____
1234

A_B_
_AB_
__AB
_A_B

The rest positions autoamtically are filled by C,D

==========================
*/

void solve(){
  
}

int main(){

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}