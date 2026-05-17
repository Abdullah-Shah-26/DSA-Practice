#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    //! Greedy - 2 - Pointer
    sort(begin(people),end(people));
    int n = people.size();
    int boats = 0;
    int i = 0, j = n-1;
    // [1,4,6,9] limit = 10
    while(i <= j){
      if(people[i] + people[j] <= limit){
        i++;
        j--;
      } else {
        // Send the heavier guy
        j--;
      }
      boats++;
    } 
    return boats;  
    }
};