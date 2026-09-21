#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countIntersectingIntervals(vector<vector<int>> &intervals) {
    vector<int> L, R;

    int n = intervals.size();

    for (auto &it : intervals) {
      L.push_back(it[0]);
      R.push_back(it[1]);
    }

    sort(begin(L), end(L));
    sort(begin(R), end(R));

    long long nonIntersecting = 0;

    // For this start it find's count of ends that are lesser than this start
    // That means no of non intersecting intervals

    for (int i = 0; i < L.size(); i++)
      nonIntersecting += lower_bound(begin(R), end(R), L[i]) - begin(R);

    return 1LL * n * (n - 1) / 2 - nonIntersecting;
  }
};