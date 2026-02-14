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
// 4 Approaches
class Solution {
public:
// TC = O(N)
// SC = O(N)
int f(int n, int k){
   // Recursive Approach
    if(n == 1)
    {
      return 0; // Only 1 element is left
    }
    int idx = f(n-1,k);
    // Convert idx to the original idx in original array
    idx = (idx + k)%n;

    return idx;     
}

    int findTheWinner(int n, int k) {
    /*
    Iterative Version 
    TC = O(N)
    SC = O(1)
    int val = 0;
    for(int  size = 2; size <= n; size++){
      val = (val + k) % size;
    }    
    return val + 1;



    TC = O(N^2)
    
    vector<int>arr;
    for(int i = 1; i <= n; i++){
      arr.push_back(i);
    }
    int i = 0;
    while(arr.size() > 1){ // O(N)
      int idx = (i + k - 1) % arr.size();
      
      arr.erase(arr.begin() + idx); // O(N) -> Elements shift after erasing
      
      i = idx;
    }
    return arr[0];


   Queue Simulation 
    TC = O(N * K)
    SC = O(N)

    queue<int>q;
    for(int i = 1 ;i <= n ;i++){
      q.push(i);
    }

    while(q.size() > 1){
      for(int cnt = 1; cnt <= k-1; cnt++){
        q.push(q.front());
        q.pop();
      }
      Remove kth guy
      q.pop();
    }
    return q.front();

    */
    return f(n,k) + 1; 
    }
};