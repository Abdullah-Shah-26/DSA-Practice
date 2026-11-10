#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  vector<int> lps(n, 0);

  // LPS array
  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];

    while (j > 0 && s[i] != s[j]) {
      j = lps[j - 1];
    }

    if (s[i] == s[j]) {
      j++;
    }

    lps[i] = j;
  }

  // Count occurrences using LPS
  vector<int> cnt(n + 1, 0);

  for (int i = 0; i < n; i++)
    cnt[lps[i]]++;

  // Propagate counts to smaller borders
  for (int len = n; len >= 1; len--)
    cnt[lps[len - 1]] += cnt[len];

  // Include the prefix occurrence at the beginning
  for (int len = 1; len <= n; len++) {
    cnt[len]++;
  }

  vector<int> ans;

  for (int len = n; len > 0; len = lps[len - 1]) {
    ans.push_back(len);
  }

  reverse(ans.begin(), ans.end());

  cout << ans.size() << '\n';

  for (int len : ans) {
    cout << len << " " << cnt[len] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
