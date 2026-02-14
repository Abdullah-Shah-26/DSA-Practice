#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using lll = __int128_t;
using ulll = __uint128_t;
using ld = long double;

using pi = pair<int,int>;
using pll = pair<ll,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// -------- lll (__int128) I/O --------
lll readlll(){
    string s; cin >> s;
    lll x = 0; int i = 0; bool neg = false;
    if(!s.empty() && s[0] == '-') neg = true, i = 1;
    for(; i < (int)s.size(); i++) x = x * 10 + (s[i] - '0');
    return neg ? -x : x;
}
void printlll(lll x){
    if(x == 0){ cout << 0; return; }
    if(x < 0) cout << '-', x = -x;
    string s;
    while(x){ s.push_back(char('0' + (int)(x % 10))); x /= 10; }
    reverse(s.begin(), s.end());
    cout << s;
}
// -----------------------------------

// -------- Fast vector/matrix input ---
#define rv(a) for(auto &x : (a)) cin >> x
#define rm(mat) for(auto &r : (mat)) for(auto &x : (r)) cin >> x
// -----------------------------------

void solve(){
    int n; 
    cin >> n;
    
}

int main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}

class Solution {
public:
// Build string length L from C chars - TC = O(C^L) * n for checking if its a subsequence 
    bool isSubsequence(string &s, string &curr, const int &k){
      int i = 0, j = 0;
      int n = s.size();
      int subseqLen = curr.size();

      while(i < n && j < k * subseqLen){
        if(s[i] == curr[j%subseqLen]){
          j++;
        }
        i++;
      }
    return j == k * subseqLen;
  }

    bool backTrack(string &s,vector<bool>&canUse, vector<int>&requiredFreq, string &curr, string &res, const int &maxLen, const int &k){
    
    if(curr.size() == maxLen){
      if(isSubsequence(s,curr,k)){
        res = curr;
        return true;
      }
      return false;
    }

    for(int i = 25; i >= 0; i--){
      if(canUse[i] == false || requiredFreq[i] == 0){
        continue;
      }

      char ch = i + 'a';
      curr.push_back(ch);
      requiredFreq[i]--;

      if(backTrack(s, canUse, requiredFreq, curr, res, maxLen, k)){
        return true;
      }

      curr.pop_back();
      requiredFreq[i]++;
    }
    return false;
  }

    string longestSubsequenceRepeatedK(string s, int k){
    int n = s.size();

    int freq[26] = {0};
    for(char &ch : s){
      freq[ch-'a']++;
    }

    vector<bool>canUse(26,0);
    vector<int>requiredFreq(26,0);        
    
    for(int i = 0; i < 26; i++){
      if(freq[i] >= k){
        canUse[i] = true;
        requiredFreq[i] = freq[i]/k;
      }
    }

    int maxLen = n/k;

    string curr = "";
    string res = "";
    
    for(int len = maxLen; len >= 0; len--){
      vector<int>tempFreq = requiredFreq;
      if(backTrack(s, canUse, tempFreq, curr, res, len, k) == true){
        return res;
      }
    }

    return res;
    }
};