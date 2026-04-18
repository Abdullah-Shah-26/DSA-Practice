#include <bits/stdc++.h>
using namespace std;

//! Greedy + Math

class Solution {
  public:
    int n;
    bool stoneGameIX(vector<int>& stones) {
    n = stones.size();

    vector<int> a(3, 0);

    for(int x : stones){
      a[x%3]++;
    } 

    int c0 = a[0], c1 = a[1], c2 = a[2];

    if(c0 % 2 == 0){
      return (c1 > 0 && c2 > 0);
    }
    else{
      return abs(c1 - c2) > 2;
    }
    }
};