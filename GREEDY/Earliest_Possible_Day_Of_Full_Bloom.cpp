#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int earliestFullBloom(vector<int> &pt, vector<int> &gt) {
    int n = pt.size();

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
      a[i] = {pt[i], gt[i]};

    // Sorted according to grow time (Largest grow time first)
    sort(begin(a), end(a),
         [&](auto &p1, auto &p2) { return p1.second > p2.second; });

    int prevPlantDays = 0;
    int maxBloomDays = 0;

    for (int i = 0; i < n; i++) {
      int curPlantTime = a[i].first;
      int curGrowTime = a[i].second;

      prevPlantDays += curPlantTime;

      maxBloomDays = max(maxBloomDays, prevPlantDays + curGrowTime);
    }

    return maxBloomDays;
  }
};