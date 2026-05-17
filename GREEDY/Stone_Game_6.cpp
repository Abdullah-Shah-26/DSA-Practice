#include <bits/stdc++.h>
using namespace std;

//! Greedy

class Solution {
  public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
    int n = alice.size();

    vector<pair<int,int>> arr;

    for(int i = 0; i < n; i++){
        arr.push_back({alice[i] + bob[i], i});
    }

    sort(arr.rbegin(), arr.rend());

    int s1 = 0, s2 = 0;
    bool flag = 1;

    for(auto [sum, i] : arr){
        if(flag){
            s1 += alice[i];
        } else {
            s2 += bob[i];
        }
        flag = !flag;
    }

    return (s1 == s2) ? 0 : ((s1 > s2) ? 1 : -1);
    }
};