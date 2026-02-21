#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void printBinary(int n)
{
  for(int i = 3;i >= 0; --i)
  {
    cout << ((n >> i) & 1);
  }
  cout << endl;
}

void solve() {
  printBinary(9);
    int a = 9;
    int i= 0;
    if((a & (1 << i)) != 0 )
    cout << "Bit Set" << endl;
    else 
    cout << "Bit Not Set" << endl;        
}

int main() {
    fastio;
    solve();
    return 0;
}