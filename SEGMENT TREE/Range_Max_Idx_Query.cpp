#include <bits/stdc++.h>
using namespace std;
//!  TC = O(log N) 
//!  SC = O(4N)

//! RMIQ 
vector<int> arr = {1, 2, 3, 4, 5};
int n = arr.size();
vector<int> segTree(4 * n);

void buildTree(int i, int l, int r)
{
  if (l == r)
  {
    segTree[i] = l; // or arr[l];
    return;
  }
  int mid = l + (r - l) / 2;
  buildTree(2 * i + 1, l, mid);
  buildTree(2 * i + 2, mid + 1, r);

  int leftMaxIdx = segTree[2 * i + 1];
  int rightMaxIdx = segTree[2 * i + 2];

  if (arr[leftMaxIdx] >= arr[rightMaxIdx])
  {
    segTree[i] = leftMaxIdx;
  }
  else
  {
    segTree[i] = rightMaxIdx;
  }
}

int QuerySegTree(int st, int end, int i, int l, int r)
{
  if (l > end || r < st)
  {
    return -1;
  }
  if (l >= st && r <= end)
  {
    return segTree[i];
  }
  int mid = (l + r) >> 1;

  int leftMaxIdx = QuerySegTree(st, end, 2 * i + 1, l, mid);
  int rightMaxIdx = QuerySegTree(st, end, 2 * i + 2, mid + 1, r);

  // Edge Case
  if (leftMaxIdx == -1)
    return rightMaxIdx;
  if (rightMaxIdx == -1)
    return leftMaxIdx;

  if (arr[leftMaxIdx] >= rightMaxIdx)
  {
    return leftMaxIdx;
  }
  else
  {
    return rightMaxIdx;
  }
}
