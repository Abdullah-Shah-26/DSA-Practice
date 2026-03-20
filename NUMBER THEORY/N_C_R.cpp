#include <bits/stdc++.h>
using namespace std;

//* Tell the rth element at that place
int NCR(int n, int r) // TC = O(r)  SC = O(1)
{
  int res = 1;
  for (int i = 0; i < r; i++)
  {
    res = res * (n - i);
    res = res / (i + 1);
  }
  return res;
}

//! Brute Force to Print Nth Row of Pascal's Triangle
//* TC = O(N * R)
void BF(int n)
{
  for (int c = 1; c < n; c++)
  {
    cout << NCR(n - 1, c - 1) << " ";
  }
}

//! Optimized Approach to Print Nth Row of Pascal's Triangle
void Optimized(int n)
{
  int ans = 1;
  cout << ans << " ";
  for (int r = 1; r < n; r++)
  {
    ans = ans * (n - r);
    ans = ans / r;
    cout << ans << " ";
  }
}

//* Print the rth row of Pascal's Triangle
void printPascalRow(int r, int n)
{
  {
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
      ans = ans * (n - i);
      ans = ans / i;
      cout << ans << " ";
    }
  }
}

class Solution {
public:
    vector<int>generateRow(int row)
    {
      long long ans = 1;
      vector<int>ansRow;
      ansRow.push_back(1);
      for(int col = 1; col < row; col++) // TC = O(r)
      {
        ans *= (row - col);
        ans /= col;
        ansRow.push_back(ans);
      }
      return ansRow;
    }
    vector<vector<int>> generate(int N) {
      vector<vector<int>>ans;
      for(int i = 1; i <= N; i++) // O(N x R)
      {
        ans.push_back(generateRow(i));
      }
      return ans;
    }
};


int main()
{
  int n = 5;
  NCR(5, 2);
}

