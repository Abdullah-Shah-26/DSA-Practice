#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string word;
vector<vector<char>> grid;

int row[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int col[8] = {1, -1, 0, 0, 1, -1, 1, -1};

bool dfs(int idx, int i, int j, int dir) {
  if (idx == word.size())
    return true;

  if (i < 0 || j < 0 || i >= n || j >= n)
    return false;

  if (grid[i][j] != word[idx])
    return false;

  return dfs(idx + 1, i + row[dir], j + col[dir], dir);
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];

  cin >> word;

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] != word[0])
        continue;

      // To lock direction & search in straight line across all 8 directions
      for (int dir = 0; dir < 8; dir++) 
        cnt += dfs(1, i + row[dir], j + col[dir], dir);
    }
  }

  cout << cnt << endl;

  return 0;
}