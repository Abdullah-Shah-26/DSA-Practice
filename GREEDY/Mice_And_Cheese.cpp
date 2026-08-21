#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;

class Solution {
public:
  int miceAndCheese(vector<int> &r1, vector<int> &r2, int k) {
    vector<T> loss; // reward2[i] - reward1[i]

    for (int i = 0; i < r1.size(); i++)
      loss.push_back({r2[i] - r1[i], r1[i], r2[i]});

    sort(begin(loss), end(loss));

    int score = 0;

    // For mice1 consume Top k with min loss

    for (int i = 0; i < loss.size(); i++) {
      auto [net, mice1, mice2] = loss[i];

      if (i < k)
        score += mice1;
      else
        score += mice2;
    }

    return score;
  }
};