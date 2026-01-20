#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

class Solution
{
public:
  void nearlySorted(vector<int> &arr, int k)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
      pq.push(arr[i]);
      if (pq.size() > k)
      {
        ans.push_back(pq.top());
        pq.pop();
      }
    }
    while (!pq.empty())
    {
      ans.push_back(pq.top());
      pq.pop();
    }
    arr = ans;
  }
};