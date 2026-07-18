#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  set<pair<int, int>> st;
  vector<pair<int, int>> pts;

  int ans = 1e9;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    st.insert({x, y});
    pts.push_back({x, y});
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {

      auto [x1, y1] = pts[i];
      auto [x2, y2] = pts[j];

      // Vertical side
      if (x1 == x2) {
        int side = abs(y1 - y2);

        if (side == 0)
          continue;

        // Square to right
        if (st.count({x1 + side, y1}) && st.count({x2 + side, y2}))
          ans = min(ans, side);

        // Square to left
        if (st.count({x1 - side, y1}) && st.count({x2 - side, y2}))
          ans = min(ans, side);
      }

      // Horizontal side
      else if (y1 == y2) {
        int side = abs(x1 - x2);

        if (side == 0)
          continue;

        // Square above
        if (st.count({x1, y1 + side}) && st.count({x2, y2 + side}))
          ans = min(ans, side);

        // Square below
        if (st.count({x1, y1 - side}) && st.count({x2, y2 - side}))
          ans = min(ans, side);
      }
    }
  }

  if (ans == 1e9)
    cout << 0 << '\n';
  else
    cout << ans << '\n';

  return 0;
}
