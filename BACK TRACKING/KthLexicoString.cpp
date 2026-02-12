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
    string ans = "";
    void solve(string &curr,const int &n, const int &k, int &cnt){
     

      if(curr.size() == n){
          cnt++;
           
          if(cnt == k){
            ans = curr;
          }
          return;
      }


      for(char ch = 'a'; ch <= 'c'; ch++){
        if(!curr.empty() && curr.back() == ch){
          continue;
        }

        curr += ch;
        solve(curr, n, k, cnt);
        curr.pop_back();
      }
    }

    string getHappyString(int n, int k) {
    // TC = O(3 * 2^(N-1))
    // SC = O(N)

    string curr = "";
    int cnt = 0;
    solve(curr, n, k, cnt);    
    return ans;
    }
};