#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
  long long subArrayRanges(vector<int> &arr)
  {
    int n = arr.size();
    stack<pair<int, int>> Left1, Right1; // Sum of Subarr Min
    stack<pair<int, int>> Left2, Right2; // Sum of Subarr Max
    vector<int> L1(n, 0), R1(n, 0), L2(n, 0), R2(n, 0);

    for (int i = 0; i < n; i++)
    {
      int cnt1 = 1, cnt2 = 1;
      // For Min
      while (!Left1.empty() && Left1.top().first > arr[i])
      {
        cnt1 += Left1.top().second;
        Left1.pop();
      }
      L1[i] = cnt1;
      Left1.push({arr[i], cnt1});
      // For Max
      while (!Left2.empty() && Left2.top().first < arr[i])
      {
        cnt2 += Left2.top().second;
        Left2.pop();
      }
      L2[i] = cnt2;
      Left2.push({arr[i], cnt2});
    }
    for (int i = n - 1; i >= 0; i--)
    {
      int cnt1 = 1, cnt2 = 1;
      // For Min
      while (!Right1.empty() && Right1.top().first >= arr[i])
      {
        cnt1 += Right1.top().second;
        Right1.pop();
      }
      R1[i] = cnt1;
      Right1.push({arr[i], cnt1});
      // For Max
      while (!Right2.empty() && Right2.top().first <= arr[i])
      {
        cnt2 += Right2.top().second;
        Right2.pop();
      }
      R2[i] = cnt2;
      Right2.push({arr[i], cnt2});
    }
    long long res1 = 0, res2 = 0;

    for (int i = 0; i < n; i++)
    {
      res1 += 1LL * arr[i] * L1[i] * R1[i]; // sum of minimums
      res2 += 1LL * arr[i] * L2[i] * R2[i]; // sum of maximums
    }

    return res2 - res1;
  }
};