#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> resultsArray(vector<vector<int>> &queries, int k) {
    priority_queue<int> pq;

    vector<int> ans;

    for (auto &q : queries) {
      int x = q[0];
      int y = q[1];

      pq.push(abs(x) + abs(y));

      if (pq.size() > k)
        pq.pop();

      if (pq.size() == k)
        ans.push_back(pq.top());
      else
        ans.push_back(-1);
    }

    return ans;
  }
};