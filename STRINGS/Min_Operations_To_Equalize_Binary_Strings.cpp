#include <bits/stdc++.h>
using namespace std;

// Tricky BFS optimization & arithmetic observation

/*
Total idx that can be flipped = k
No of zeros that can be flipped = f
No of ones that can be flipped = (k - f)

Can't flip more than k zeros or ones

Z = current available zeros
f <= k  # Cant flip more than available zeros

f <= min(k, z)

(k - f) <= (n - z) # Cant flip more than available ones
f >= (k - n + z)
f >= 0 (Since no of zeros chosen to flip can't be -ve)

newZ = Z - f + (k - f)
     = Z + k - 2f

f range = [max(0, k - n + z), min(k, z)]
*/

class Solution {
public:
  int minOperations(string s, int k) {
    int n = s.size();

    int zeros = 0;
    for (char &ch : s)
      if (ch == '0')
        zeros++;

    if (zeros == 0)
      return 0;

    // To avoid recomputing vis states
    set<int> even, odd;
    for (int i = 0; i <= n; i++) {
      if (i & 1)
        odd.insert(i);
      else
        even.insert(i);
    }

    // dp[z] = min operations req to reach state in which we have z zeros
    vector<int> dp(n + 1, -1);
    queue<int> q;

    q.push(zeros);
    dp[zeros] = 0; // To reach these zeros we needed 0 ops

    if (zeros & 1)
      odd.erase(zeros);
    else
      even.erase(zeros);

    while (!q.empty()) {
      int z = q.front();
      q.pop();

      int minNewZ = z + k - 2 * min(k, z);
      int maxNewZ = z + k - 2 * max(0, k - n + z);

      set<int> &curSet = (minNewZ & 1) ? odd : even;
      auto it = curSet.lower_bound(minNewZ);

      while (it != curSet.end() && *it < +maxNewZ) {
        int newZ = *it;

        if (dp[newZ] == -1) {
          dp[newZ] = dp[z] + 1;

          if (newZ == 0)
            return dp[newZ];

          q.push(newZ);
        }

        it = curSet.erase(it);
      }
    }

    return -1;
  }
};