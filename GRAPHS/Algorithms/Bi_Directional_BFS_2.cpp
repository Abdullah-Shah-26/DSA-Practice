#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Open The Lock
//* TC = O(10^(4/2)) * 8  || SC = O(10^4)

class Solution {
public:
    int openLock(vector<string>& deadends, string end) {
    unordered_set<string> dead(deadends.begin(), deadends.end());    

    if(end == "0000") return 0;

    string st = "0000";

    if(dead.count(st) || dead.count(end)) return -1;

    unordered_set<string> beginSet;
    unordered_set<string> endSet;

    beginSet.insert(st);
    endSet.insert(end);

    int level = 0;

    while(!beginSet.empty() && !endSet.empty()){
      
      if(beginSet.size() > endSet.size()) swap(beginSet, endSet);

      unordered_set<string> nextLevel;

      for(auto cur : beginSet){

        for(int i = 0; i < 4; i++){

          // Increment
          string temp = cur;
          temp[i] = (cur[i] - '0' + 1) % 10 + '0';

          if(endSet.count(temp))
            return level + 1;

          if(!dead.count(temp)){
            dead.insert(temp); // Mark as vis
            nextLevel.insert(temp); // Push in q (next level)
          }

          // Decrement
          temp = cur;
          temp[i] = (cur[i] - '0' - 1 + 10) % 10 + '0';

          if(endSet.count(temp))
            return level + 1;

          if(!dead.count(temp)){
            dead.insert(temp);
            nextLevel.insert(temp);
          }

        }
      }

      level++;
      beginSet = nextLevel;
    }

    return -1;
    }
};