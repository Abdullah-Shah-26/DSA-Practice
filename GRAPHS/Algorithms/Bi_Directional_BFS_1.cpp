#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* Word Ladder Using Bi - directional BFS - much faster - Half Branching Factor

class Solution {
public:
    int ladderLength(string st, string end, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    if(!wordSet.count(end)) return 0;

    unordered_set<string> beginSet, endSet;
    
    beginSet.insert(st);
    endSet.insert(end);   
    
    int level = 1;

    while(!beginSet.empty() && !endSet.empty()){

      // Always Expand Smaller Set
      if(beginSet.size() > endSet.size()) swap(beginSet, endSet);

      unordered_set<string> nextLevel;

      for(auto word : beginSet){
        for(int i = 0; i < word.size(); i++){
          char original = word[i];

          for(char ch = 'a'; ch <= 'z'; ch++){
            word[i] = ch;

            // Meeting Point
            if(endSet.count(word)) 
              return level+1;

            // Normal Expansion
            if(wordSet.count(word)){
              nextLevel.insert(word);
              wordSet.erase(word);
            }
          }

          word[i] = original;
        }
      }

    beginSet = nextLevel;
    level++;

    }

    return 0;
    }
};