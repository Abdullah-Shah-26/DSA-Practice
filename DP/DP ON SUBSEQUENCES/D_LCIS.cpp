#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 505;
int a[MAXN], b[MAXN], len[MAXN], prevIdx[MAXN];

int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int j = 0; j < m; j++) cin >> b[j];

  fill(prevIdx, prevIdx + MAXN, -1);

  for (int i = 0; i < n; i++) {
    int best = 0, bestIdx = -1;
    for (int j = 0; j < m; j++) {
      // a[i] ends a chain at b[j]; extend the best smaller chain seen so far
      if (a[i] == b[j] && best + 1 > len[j]) {
        len[j] = best + 1;
        prevIdx[j] = bestIdx;
      }
      if (b[j] < a[i] && len[j] > best) {
        best = len[j];
        bestIdx = j;
      }
    }
  }

  int end = max_element(len, len + m) - len;
  cout << len[end] << "\n";

  vector<int> res;
  for (int j = (len[end] ? end : -1); j != -1; j = prevIdx[j])
    res.push_back(b[j]);

  reverse(res.begin(), res.end());
  
  for (int x : res) cout << x << " ";
  cout << "\n";
}