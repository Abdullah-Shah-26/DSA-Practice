#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

//! Profile Dp

/*
- Process Col by Col
- Each Col cell may already be occupied by horizontal dominoes from prev Col
- So Occupancy State = Represented as mask

- Col - 0
- r1 - filled
- r2 - empty
- r3 - filled

- This col can be represented as = 101

- dp[col][mask] = no of ways to tile columns [0....col-1] with occupancy pattern
mask
- where mask bit i, tells whether this cell is available [0] in current col or
got filled [1] by prevCol via horizontal dominos

! Parameters

* col = current col
* row = current row inside cur Col
* curMask = occupied cells in cur Col
* nextMask = cells that will be occupied in next Col

*/

int n, m;
int dp[1001][1 << 10];

void solve(int col, int row, int curMask, int nextMask) {

  if (row == n) { // Finished all rows of this col, transfer this way's count to
                  // next Col State
    dp[col + 1][nextMask] = (dp[col + 1][nextMask] + dp[col][curMask]) % MOD;
    return;
  }

  // Cur Cell already filled - move to next row
  if (curMask & (1 << row)) {
    solve(col, row + 1, curMask, nextMask);
    return;
  }

  //! Option 1 : Place horizontal domino
  // It fills (r,c) & (r,c+1) i.e nextCol's same row

  solve(col, row + 1, curMask, nextMask | (1 << row));

  //! Option 2 : Place vertical domino
  // It fills (r,c) & (r+1,c) i.e 2 rows of curCol but for that next row should
  // exist & unfilled

  if (row + 1 < n && !(curMask & (1 << (row + 1)))) {
    solve(col, row + 2, curMask, nextMask);
  }
}

int main() {
  fastio();

  cin >> n >> m;

  dp[0][0] = 1; // No of ways to reach col = 0 with mask = 0 [no cells of col 0
                // are prefilled] = 1 way = do nothing

  for (int col = 0; col < m; col++) {

    // Try every possible way
    for (int mask = 0; mask < (1 << n); mask++) {

      if (dp[col][mask] == 0)
        continue;

      solve(col, 0, mask, 0);
    }
  }

  cout << dp[m][0] << endl; // After Last Col, Nothing should be outside or hang
                            // out so mask = 0, No filling

  return 0;
}