#include <bits/stdc++.h>
using namespace std;

void subsequence(int arr[], int idx, int n, vector<vector<int>> &ans, vector<int> &temp)
{
  // base case
  if (idx == n)
  {
    ans.push_back(temp); // store the current subsequence
    return;
  }
  // Not incluede the current element
  subsequence(arr, idx + 1, n, ans, temp);
  // include the current element
  temp.push_back(arr[idx]);
  subsequence(arr, idx + 1, n, ans, temp);

  // Backtrack to explore other subsequences
  temp.pop_back(); // remove the last element to backtrack
}

int main()
{
  int arr[] = {1, 2, 3};
  vector<vector<int>> ans;
  vector<int> temp;
  subsequence(arr, 0, 3, ans, temp);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << "  ";
    }
    cout << endl;
  }
}