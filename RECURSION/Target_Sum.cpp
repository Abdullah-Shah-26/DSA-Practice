#include <bits/stdc++.h>
using namespace std;

bool Find(int arr[], int idx, int n, int target)
{
  if (target == 0)
  {
    return 1; // found a subset with the target sum
  }
  // base case
  if (idx == n || target < 0)
  {
    return 0;
  }

  return Find(arr, idx + 1, n, target) || Find(arr, idx + 1, n, target - arr[idx]);
  // Explore two choices: include or exclude the current element
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int target = 2;
  cout << Find(arr, 0, 5, target) << " ";
}