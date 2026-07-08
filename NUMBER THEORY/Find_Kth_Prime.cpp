#include <bits/stdc++.h>
using namespace std;

/*

Input

An integer stating the number of queries Q (equal to 50000), and Q lines follow,
each containing one integer K between 1 and 5000000 inclusive. Output

Q lines with the answer of each query: the Kth prime number.
Example

Input:
7
1
10
100
1000
10000
100000
1000000

Output:
2
29
541
7919
104729
1299709
15485863

*/

const int N = 1000005;
vector<int> primes;
vector<bool> isprime;

void sieve() {
  isprime[0] = isprime[1] = false;

  for (int i = 2; i * i <= N; i++)
    if (isprime[i])
      for (int j = i * i; j <= N; j += i)
        isprime[j] = false;

  for (int i = 2; i <= N; i++)
    if (isprime[i])
      primes.push_back(i);
}

int main() { 
  isprime.assign(N + 1, false); 
  sieve();

  int n, q;
  cin >> q;

  while(q--){
    cin >> n;
    cout << primes[n-1] << endl;
  }
}