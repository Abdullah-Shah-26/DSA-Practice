#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(10^4 * 8)  || SC = O(10^4)
// TODO  : BFS - Level Order

class Solution {
  public:
    // 4 wheels * 2 directions = 8 neighbours
    void fillNeighbours(queue<string> &q, string &cur, unordered_set<string> &deadEnd){
      for(int i = 0; i < 4; i++){
        char ch = cur[i];

        char dec = ch == '0' ? '9' : ch - 1;
        char inc = ch == '9' ? '0' : ch + 1;

        cur[i] = dec; // Decrease by 1
        if(!deadEnd.count(cur)) {
          deadEnd.insert(cur); // Mark as visited 
          q.push(cur); // Push to next level
        } 
         
        cur[i] = inc; // Increase by 1
        if(!deadEnd.count(cur)) {
          deadEnd.insert(cur);
          q.push(cur);
        }

        cur[i] = ch;
      }
    }

    int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadEnds(deadends.begin(), deadends.end());

    string st = "0000";

    if(deadEnds.count(target)) return -1;
    if(deadEnds.count(st)) return -1;

    queue<string> q;
    q.push(st);

    int level = 0;

    while(!q.empty()){
      int size = q.size();

      while(size--){
        string cur = q.front();
        q.pop();

        if(cur == target) 
           return level;
      
        fillNeighbours(q, cur, deadEnds);
      }
      
      level++;
    }

    return -1;    
    }
};