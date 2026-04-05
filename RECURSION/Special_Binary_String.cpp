#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N^2 Log N) || SC = O(N)

class Solution {
public:
    string makeLargestSpecial(string s) {
    vector<string> specials;

    int st = 0;
    int sum = 0;

    for(int i = 0; i < s.size(); i++){
      sum += s[i] == '1' ? 1 : -1;
    
      if(sum == 0){
        string inner = s.substr(st + 1, i - st - 1);
        specials.push_back("1" + makeLargestSpecial(inner) + "0");
        st = i + 1;
      }
    }    

    sort(begin(specials), end(specials), greater<string>());

    string ans;
    for(auto &str : specials){
      ans +=  str;
    }

    return ans;
    }
};