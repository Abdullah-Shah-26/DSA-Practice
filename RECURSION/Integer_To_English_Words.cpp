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

    string belowTen[10] = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine"
    };        

    string belowTwenty[10] = {
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    string tens[10] = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string solve(int n) {

        if (n < 10)
            return belowTen[n];

        if (n < 20)
            return belowTwenty[n - 10];

        if (n < 100)
            return tens[n / 10] +
                   (   ? " " + belowTen[n % 10] : "");

        if (n < 1000)
            return belowTen[n / 100] + " Hundred" +
                   (n % 100 ? " " + solve(n % 100) : "");

        if (n < 1000000)
            return solve(n / 1000) + " Thousand" +
                   (n % 1000 ? " " + solve(n % 1000) : "");

        if (n < 1000000000)
            return solve(n / 1000000) + " Million" +
                   (n % 1000000 ? " " + solve(n % 1000000) : "");

        return solve(n / 1000000000) + " Billion" +
               (n % 1000000000 ? " " + solve(n % 1000000000) : "");
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        return solve(num);
    }
};

