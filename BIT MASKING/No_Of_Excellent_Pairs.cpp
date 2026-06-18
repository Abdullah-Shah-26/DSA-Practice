#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*
  1 0 1 0 1 - 3
  1 1 1 0 1 - 4
  ---------
  1 1 1 0 1 - OR = (3+4) - 3(No of common setbits in both) = 4
  ---------
  1 0 1 0 1 - AND = No of common setbits inboth = 3
  ---------

  OR = No of setbits in (nums1 + nums2) - No of common setbits in both
  +
  AND =  No of common setbits in both
  --------------------------------------------
  OR + AND = sum of setbits in (Nums1 + Nums2) >= k (Excellent Pair)
  */

  // int NoofSetBits(int x)
  // {
  //   int cnt = 0;
  //   for(int i = 31; i>=0; i--)
  //   {
  //     if((1 << i) & x)
  //     cnt++;
  //   }
  //   return cnt;
  // }

  long long countExcellentPairs(vector<int> &nums, int k) {
    unordered_set<int> st;

    for (auto &i : nums)
      st.insert(i);

    vector<int> bits; // all no of nums represented in no of setbit form
    for (auto &i : st)
      bits.push_back(__builtin_popcount(i));

    long long res = 0;

    sort(bits.begin(), bits.end());

    int n = bits.size();

    // bits[i] + bits[j] >= k
    // bits[j] >= k - bits[i]

    for (int i = 0; i < n; i++) {
      int need = k - bits[i];   

      // gives the idx of first elem - bits[j] just >= need
      int idx = lower_bound(bits.begin(), bits.end(), need) - bits.begin();

      res += (n - idx);
    }

    return res;
  }
};