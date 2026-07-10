#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long countPairs(vector<int> &nums, int k) {
    ll ans = 0;
    unordered_map<int, int> freq;

    for (int &x : nums) {
      ll curGcd = __gcd(x, k);

      for (auto &[prevGcd, cnt] : freq)
        if ((prevGcd * curGcd) % k == 0)
          ans += freq[prevGcd];

      freq[curGcd]++;
    }

    return ans;
  }
};

/*

12 = 2^2 * 3
18 = 2 * 3^2

Common part = 2*3 = 6
gcd(12, 18) = 6

k = 12                 New Guy
arr[] =  [6, 18, 30 42]  8
g(x,k) = [6, 6,  6, 6]   4

Map : 
[6] - [4]

prevGcd = 6, curGcd = 4
(6 * 4) = 24 % 12 == 0
cnt += freq[prevGcd]
*/