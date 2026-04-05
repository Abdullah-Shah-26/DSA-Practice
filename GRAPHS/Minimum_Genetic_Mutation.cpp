#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS - Level Order 
int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> st(bank.begin(), bank.end());

    if(!st.count(end)) return -1; // small pruning

    queue<string> q;
    q.push(start);

    int level = 0;

    while(!q.empty()){
        int size = q.size();

        while(size--){
            string cur = q.front();
            q.pop();

            if(cur == end) return level;

            for(char ch : {'A','C','G','T'}){
                for(int i = 0; i < cur.size(); i++){
                    string nei = cur;
                    nei[i] = ch;

                    if(st.count(nei)){
                        st.erase(nei);   // mark visited HERE
                        q.push(nei);
                    }
                }
            }
        }
        level++;
    }

    return -1;
}