#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
  int sumOfMax(vector<int> &arr)
  {
    stack<pair<int, int>> left, right;
    int n = arr.size();
    vector<int> L(n, 0), R(n, 0);
    for (int i = 0; i < n; i++)
    {
      int cnt = 1;
      while (!left.empty() && left.top().first < arr[i])
      {
        cnt += left.top().second;
        left.pop();
      }
      L[i] = cnt;
      left.push({arr[i], cnt});
    }
    for (int i = n - 1; i >= 0; i--)
    {
      int cnt = 1;
      while (!right.empty() && right.top().first <= arr[i])
      {
        cnt += right.top().second;
        right.pop();
      }
      R[i] = cnt;
      right.push({arr[i], cnt});
    }
    long long res = 0;
    int mod = 1e9;
    for (int i = 0; i < n; i++)
    {
      res = res + (arr[i] * (L[i] * R[i]));
    }
    return (int)res;
  }
};