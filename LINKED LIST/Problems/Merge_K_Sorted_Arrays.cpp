#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> mergeKArrays(vector<vector<int>> arr, int k) {

    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < k; i++) {
      temp.push_back({arr[i][0], {i, 0}});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        p(temp.begin(), temp.end());

    vector<int> ans;

    pair<int, pair<int, int>> element;
    int i, j;

    while (!p.empty()) {
      element = p.top();
      p.pop();
      ans.push_back(element.first);
      i = element.second.first;
      j = element.second.second;

      if (j + 1 < k)
        p.push({arr[i][j + 1], {i, j + 1}});
    }
    return ans;
  }
};

class Solution {
public:
  void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end) {
      if (arr[i] <= arr[j]) {
        temp.push_back(arr[i]);
        i++;
      } else {
        temp.push_back(arr[j]);
        j++;
      }
    }

    while (i <= mid) {
      temp.push_back(arr[i]);
      i++;
    }

    while (j <= end) {
      temp.push_back(arr[j]);
      j++;
    }

    for (int i = 0; i < temp.size(); i++) {
      arr[i + st] = temp[i];
    }
  }

  void mergesort(vector<int> &arr, int start, int end, int portion, int k) {
    if (portion < 2)
      return;

    int mid = start + (portion / 2) * k - 1;

    mergesort(arr, start, mid, portion / 2, k);
    mergesort(arr, mid + 1, end, portion - portion / 2, k);
    merge(arr, start, mid, end);
  }

  vector<int> mergeKArrays(vector<vector<int>> arr, int k) {

    vector<int> ans;
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        ans.push_back(arr[i][j]);

    mergesort(ans, 0, ans.size() - 1, k, k);
    return ans;
  }
};