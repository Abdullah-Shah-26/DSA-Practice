#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }


//! BFS 
//* TC = O(N * L * 26) && SC = O(N)

class Solution {
  public:
    int ladderLength(string start, string end, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());

    if(!st.count(end)) return 0;

    queue<string> q;
    q.push(start);
    st.erase(start); 

    int level = 1;

    while(!q.empty()){
      int size = q.size();

      while(size--){
        string cur = q.front();
        q.pop();

        if(cur == end) return level;

        for(int i = 0; i < cur.size(); i++){
          char original = cur[i];

          for(char ch = 'a'; ch <= 'z'; ch++){
            cur[i] = ch;

            if(st.count(cur)){
              q.push(cur);
              st.erase(cur);
            }
          }

          cur[i] = original;
        }
      }

      level++;
    }

    return 0;
    }
};