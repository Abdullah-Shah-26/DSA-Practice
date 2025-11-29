#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;                 
    vector<int> a(n);
    for (auto &x : a) cin >> x;  

    int even = 0, odd = 0;
    for (int x : a) {
      if (x % 2 == 0) even++;
      else odd++;
    }

    if (even > 0 && odd > 0) {
      sort(a.begin(), a.end());
      for (auto x : a) cout << x << " ";
      cout << "\n";
      continue;   
    } 
    else {
      for (auto x : a) cout << x << " ";
      cout << "\n";
      continue;   
    }
  }

  return 0;
}
