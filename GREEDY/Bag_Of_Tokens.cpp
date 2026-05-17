#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
//! Greedy + 2 Pointer
class Solution
{
public:
  int bagOfTokensScore(vector<int> &tokens, int power)
  {
    int maxi = 0;
    int n = tokens.size();
    sort(begin(tokens), end(tokens));

    int i = 0, j = n - 1;
    int score = 0, maxScore = 0;
    while (i <= j)
    {
      if (power >= tokens[i])
      {
        power -= tokens[i];
        score++;
        if (score > maxScore)
        {
          maxScore = score;
        }
        i++;
      }
      else if (score >= 1)
      {
        score--;
        power += tokens[j];
        j--;
      }
      else
      {
        return maxScore;
      }
    }
    return maxScore;
  }
};