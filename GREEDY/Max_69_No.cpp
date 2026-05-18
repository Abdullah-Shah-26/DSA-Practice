#include <bits/stdc++.h>
using namespace std;

// TC = O(LogN) | SC = O(1)

class Solution {
  public:
    int maximum69Number (int num) {
    int pos = -1;
    int cnt = 0;
    int temp = num;

    while(temp != 0) {
      int rem = temp % 10;
      if(rem == 6){
        pos = cnt;
      }
      temp /= 10;
      cnt++;
    }   

    if(pos != -1){
      return num + 3 * pow(10, pos); 
    }

    return num;
    }
};