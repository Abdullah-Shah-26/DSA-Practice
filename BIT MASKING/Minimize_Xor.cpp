#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int targetSetBits = __builtin_popcount(num2);
    int ans = 0;

    // L -> R & when we have bit set in num1, set it in ans, cause xor of same bits becomes 0
    for(int i = 31; i >= 0 && targetSetBits > 0; i--){
      if(num1 & (1 << i)){
        ans |= (1 << i);
        targetSetBits--;
      }
    }

    // R -> L & place the left out setBits in remaining positions, LSB -> MSB so we build minimally
    for(int i = 0; i <= 31 && targetSetBits > 0; i++){
      if(!(ans & (1 << i))){
        ans |= (1 << i);
        targetSetBits--;
      }
    }

    return ans;
  }
}; 