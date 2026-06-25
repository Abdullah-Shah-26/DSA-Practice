#include <bits/stdc++.h>
using namespace std;

// Rolling GCD states

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) 
    cin >> x;

  // total[g] = total subarrays in whole array having gcd = g
  map<ll, ll> total;

  // states for subarrays ending at previous index
  map<ll, ll> ending;

  for (ll x : a) {
    map<ll, ll> nextEnding;

    // start new subarray
    nextEnding[x]++;

    // extend old subarrays
    for (auto& [g, cnt] : ending) {
      ll newGcd = gcd(g, x);
      nextEnding[newGcd] += cnt;
    }

    // Add to global ans
    for (auto [g, cnt] : nextEnding) {
      total[g] += cnt;
    }

    ending = nextEnding;
  }

  int q;
  cin >> q;

  while (q--) {
    ll x;
    cin >> x;

    cout << total[x] << "\n";
  }

  return 0;
}