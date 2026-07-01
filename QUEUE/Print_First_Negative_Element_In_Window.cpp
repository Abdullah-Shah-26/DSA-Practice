#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> FirstNegativeInteger(vector<int> &arr, int k) {

    int n = arr.size();
    vector<int> ans;
    queue<int> q; // stores idx of -ve elements

    // push first k-1 elements
    for (int i = 0; i < k - 1; i++) {
      if (arr[i] < 0)
        q.push(i);
    }

    // slide the window
    for (int i = k - 1; i < n; i++) {

      // add current element
      if (arr[i] < 0)
        q.push(i);

      // remove idx which are out of current window
      while (!q.empty() && q.front() < i - k + 1)
        q.pop();

      // first -ve element of current window
      if (q.empty())
        ans.push_back(0);
      else
        ans.push_back(arr[q.front()]);
    }

    return ans;
  }
};