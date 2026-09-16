#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  ll f(ll firstHalf, bool isEven){
    ll resNo = firstHalf;

    if(!isEven){
      firstHalf /= 10; 
    }

    while(firstHalf > 0){
      int digit = firstHalf % 10;
      resNo = (resNo * 10) + digit;
      firstHalf /= 10;
    }

    return resNo;
  }

  string nearestPalindromic(string s) {
    int L = s.size();
    int mid = L/2; 

    int firstHalfLen = (L & 1) ? (mid + 1) : mid;
    ll firstHalf = stoll(s.substr(0, firstHalfLen));

    vector<ll> ans; // Possible candidates

    ans.push_back(f(firstHalf, L % 2 == 0));
    ans.push_back(f(firstHalf + 1, L % 2 == 0));
    ans.push_back(f(firstHalf - 1, L % 2 == 0));
    ans.push_back((ll)pow(10, L - 1) - 1); // For 1001 , ans = 999
    ans.push_back((ll)pow(10, L) + 1); // For 99, ans = 101

    ll res = LLONG_MAX;
    ll diff = LLONG_MAX;
    ll originalNo = stoll(s);

    for(auto num : ans){
      if(num == originalNo)
        continue;

      if(abs(num - originalNo) < diff){
        diff = abs(num - originalNo);
        res = num;
      }
      else if(abs(num - originalNo) == diff){
        res = min(res, num);
      }
    }

    return to_string(res);
  }
};