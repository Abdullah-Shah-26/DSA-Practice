#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
  vector<int> nextGreater(vector<int> &arr)
  {
    stack<int> st;
    int n = arr.size();
    vector<int> Nge(n, 0);
    // TC = O(2N + 2N) - push & pop in stack
    // SC = O(2N + n) - stack + Nge
    for (int i = 2 * n - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= arr[i % n])
      {
        st.pop();
      }
      if (i < n)
      {
        // we  need nge for real guys i < n
        Nge[i] = st.size() == 0 ? -1 : st.top();
      }
      st.push(arr[i % n]);
    }
    return Nge;
  }
};