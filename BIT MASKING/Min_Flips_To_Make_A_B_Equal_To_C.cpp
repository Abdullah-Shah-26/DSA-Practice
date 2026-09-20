#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minFlips(int a, int b, int c) {
    string A = bitset<32>(a).to_string();
    string B = bitset<32>(b).to_string();
    string C = bitset<32>(c).to_string();

    int cnt = 0;

    for (int i = 0; i < 32; i++) {
      int x = A[i] - '0';
      int y = B[i] - '0';
      int z = C[i] - '0';

      if (z == 0) {
        // Need x | y = 0 => both must be 0.
        cnt += x + y;
      } else {
        // Need x | y = 1 => at least one must be 1.
        if (x == 0 && y == 0)
          cnt++;
      }
    }

    return cnt;
  }
};