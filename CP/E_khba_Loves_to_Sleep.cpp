#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;
 
        vector<long long> a(n);
        for (auto &v : a) cin >> v;
        sort(a.begin(), a.end());
 
        if (k >= x + 1) {
            for (int i = 0; i <= x; i++) cout << i << " ";
            cout << "\n";
            continue;
        }
 
        vector<pair<long long, long long>> gaps;
 
        if (a[0] > 0)
            gaps.push_back({a[0], 0});
        for (int i = 0; i + 1 < n; i++) {
            long long len = (a[i + 1] - a[i]) / 2;
            long long mid = (a[i + 1] + a[i]) / 2;
            gaps.push_back({len, mid});
        }
        if (a.back() < x)
            gaps.push_back({x - a.back(), x});
 
        sort(gaps.rbegin(), gaps.rend());
 
        vector<long long> ans;
        for (int i = 0; i < k && i < (int)gaps.size(); i++) {
            ans.push_back(min(max(gaps[i].second, 0LL), x));
        }
 
        sort(ans.begin(), ans.end());
        for (auto p : ans) cout << p << " ";
        cout << "\n";
    }
}
