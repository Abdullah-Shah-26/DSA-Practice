#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll m;
        cin >> n >> m;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        ll ans = 0, coins = 0;
        ll sum = 0, st = 0;
        for(int i = 0;i < n;i++)
        {
            sum+= a[i];
            while(sum > m || (st < n && a[i]- a[st] > 1))
            {
                sum-=a[st];
                st++;
            }
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
}
