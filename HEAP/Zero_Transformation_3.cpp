#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
static const int MOD = 1'000'000'007;
inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
class Solution
{
public:
  // TC = O((N + Q) Log Q)
  // SC = O(Q)
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
  {
    int Q = queries.size();
    int n = nums.size();
    priority_queue<int> maxHeap; // To Store Farthest Endings
    priority_queue<int, vector<int>, greater<int>> past;
    // To Store Past Endings of Queries
    sort(begin(queries), end(queries)); // Q Log Q
    int j = 0;
    int usedCnt = 0;
    for (int i = 0; i < n; i++)
    {
      // Does this query impact i - push in MaxHeap
      while (j < Q && queries[j][0] == i)
      { // Q Log Q
        maxHeap.push(queries[j][1]);
        j++;
      }
      // Check if we can impact current i from any past queries
      nums[i] -= past.size();
      while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i)
      { // Q log Q
        int ending = maxHeap.top();
        maxHeap.pop();
        past.push(ending);
        usedCnt++;
        nums[i]--;
      }
      if (nums[i] > 0)
      {
        return -1;
      }
      // Clear out past idx which no longer impact curr idx
      while (!past.empty() && past.top() <= i)
      {
        past.pop();
      }
    }
    return Q - usedCnt;
  }
};
int main()
{
  fastio();
  return 0;
}