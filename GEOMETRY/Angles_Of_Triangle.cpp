#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<double> internalAngles(vector<int> &s) {
    double a = s[0];
    double b = s[1];
    double c = s[2];

    if ((a + b) <= c || (b + c) <= a || (a + c) <= b)
      return {};

    // cos(A) = (b^2 + c^2 - a^2) / (2bc)
    // degrees = radians * 180/Pi 
    double A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / M_PI;
    double B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.0 / M_PI;
    double C = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / M_PI;

    vector<double> ans = {A, B, C};

    sort(begin(ans), end(ans));

    return ans;
  }
};