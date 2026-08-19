#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;

    for (int HH = 0; HH < 12; HH++) {
      for (int MM = 0; MM < 60; MM++) {

        if (__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn) {
          string hour = to_string(HH);
          string minute = (MM < 10 ? "0" : "") + to_string(MM);

          ans.push_back(hour + ":" + minute);
        }
      }
    }

    return ans;
  }
};