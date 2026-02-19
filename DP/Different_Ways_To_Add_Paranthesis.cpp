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

//! Interval DP
class Solution {
public:
/*
dp[l][r]={all results from every valid parenthesization of s[l..r]}

It is literally all results of that sub-expression.
*/
   vector<int> diffWaysToCompute(string s) {
    int n = s.size();
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(n));

    for(int i = 0 ;i < n; i++){
      if(isdigit(s[i])){
        int num = 0, j = i;
        while(j < n && isdigit(s[j])){
          num = num * 10 + (s[j] - '0');
          j++;
        }
        dp[i][j-1].push_back(num);
      i = j - 1; 
      }  
    }

    for(int len = 1; len <= n; len++){    
      for(int l = 0; l + len - 1 < n; l++){
        // len = r - l + 1
        int r = l + len - 1;
        for(int k = l; k <= r; k++){
          if(s[k] == '+' || s[k] == '-' || s[k] == '*'){

            for(int x : dp[l][k-1]){
              for(int y : dp[k + 1][r]){
                if(s[k] == '+') dp[l][r].push_back(x + y);
                else if(s[k] == '-') dp[l][r].push_back(x - y);
                else dp[l][r].push_back(x * y);
              }
            }
          }
        }
      }
    }
    return dp[0][n-1];
    } 
};
