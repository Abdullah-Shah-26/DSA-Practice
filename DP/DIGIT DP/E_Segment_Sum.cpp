#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;

vector<int> digits;
ll pow10[20];

pair<ll,ll> dp[20][1024][2][2];
bool vis[20][1024][2][2];

int K, N;

pair<ll,ll> dfs(int i, int mask, int tight, int lz)
{
    if(i == N)
        return {1,0};

    auto &res = dp[i][mask][tight][lz];

    if(vis[i][mask][tight][lz])
        return res;

    vis[i][mask][tight][lz] = true;

    res = {0,0};

    int ub = tight ? digits[i] : 9;
    int remaining = N - i - 1;

    for(int d = 0; d <= ub; d++)
    {
        int newTight = tight && (d == digits[i]);   // FIXED

        int newMask = mask;
        int newLz = lz;

        if(lz && d == 0)
        {
            newLz = 1;
        }
        else
        {
            newLz = 0;
            newMask = mask | (1 << d);
        }

        if(__builtin_popcount(newMask) > K)
            continue;

        auto child = dfs(i+1,newMask,newTight,newLz);

        ll cnt = child.first;
        ll sum = child.second;

        ll add = (1LL * d * pow10[remaining]) % MOD;
        add = (add * cnt) % MOD;

        res.first = (res.first + cnt) % MOD;
        res.second = (res.second + sum + add) % MOD;
    }

    return res;
}

ll f(ll x)
{
    if(x < 0) return 0;

    digits.clear();

    if(x == 0)
        digits.push_back(0);

    while(x)
    {
        digits.push_back(x%10);
        x/=10;
    }

    reverse(digits.begin(),digits.end());

    N = digits.size();

    memset(vis,0,sizeof(vis));

    auto ans = dfs(0,0,1,1);

    return ans.second % MOD;
}

void solve()
{
    ll l,r;
    cin>>l>>r>>K;

    pow10[0] = 1;
    for(int i=1;i<20;i++)
        pow10[i] = (pow10[i-1]*10)%MOD;

    ll ans = (f(r) - f(l-1)) % MOD;

    if(ans < 0) ans += MOD;

    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
        solve();
}