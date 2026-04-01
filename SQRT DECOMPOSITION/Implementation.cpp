#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int,int>;
using ppi = pair<pair<int,int>, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

//! Sparse Table is better for this problem since there are no updates here
/*
RMQSQ - Range Minimum Query 
no tags 

You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the minimum number between the range [i, j] (inclusive).

Note: the query ranges are specified using 0-based indexing.

Input
The first line contains N, the number of integers in our list (N <= 100,000). The next line holds N numbers that are guaranteed to fit inside an integer. Following the list is a number Q (Q <= 10,000). The next Q lines each contain two numbers i and j which specify a query you must answer (0 <= i, j <= N-1).

Output
For each query, output the answer to that query on its own line in the order the queries were made.

Example : 

Input:
3
1 4 1
2
1 1
1 2

Output:
4
1

*/

//! TC = O(Q * Sqrt(N)) + O(N)
//! SC = O(Sqrt(N))

const int N = 1e5 + 14;
int S = (int) sqrt(N) + 1;
int n, q, a[N], b[N];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i+=S)
    b[i/S] = *min_element(a+i, a+min(i+S, n));
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    int ans = INF;
    while(l < r)
    {
      //! Start of current Block & Does this block [L..S) lie in range [L...R) here R is exclusive
      if(l % S == 0 && l + S <= r)
      {
        ans = min(ans, b[l/S]);
        l += S;
      }
      else
        ans = min(ans, a[l++]);
    }
    cout << ans << endl;
  }
  return 0;
}

