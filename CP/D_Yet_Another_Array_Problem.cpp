#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int x, int y)
{
  if(y == 0)
  return x;
  else 
  return gcd(y, x % y);
}



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        long long g = a[0];
        for (int i = 1; i < n; i++) g = gcd(g, a[i]);
        
        if (g == 1) {
            cout << 2 << "\n"; 
            continue;
        }
        
        long long ans = -1;
        for (long long x = 2; x <= 1e6; x++) {
            if (gcd(x, g) == 1) {
                ans = x;
                break;
            }
        }
        cout << (ans == -1 ? -1 : ans) << "\n";
    }
}
