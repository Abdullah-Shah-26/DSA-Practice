/*

Micro just learned about prime numbers. But he quickly got bored of them, so he
defined a new kind of numbers and called them Prime Prime Numbers. A number X is
Prime Prime if number of prime numbers from 1 to X (inclusive) are prime. Now he
wants to find out the number of Prime Prime numbers from L to R (inclusive).
Help Micro with it.

Input:
First line consists of a single integer T denoting number of test cases
Following T lines consists of two space separated integers denoting L and R

Output:
Print the number of Prime Prime Numbers for each between L and R for each test
case in a new line.

Constraints:



Sample Input
2
3 10
4 12
Sample Output
4
5

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000000;

vector<bool> isPrime(N + 1, true);
vector<int> primeCnt(N + 1, 0);
vector<int> primePrimePref(N + 1, 0);

void sieve() {
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= N; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= N; j+=i)
        isPrime[j] = false;
    }
  }
}

void preprocess() {
  sieve();

  // primeCnt[i] = no of primes from 1 .... i
  for (int i = 1; i <= N; i++)
    primeCnt[i] = primeCnt[i - 1] + isPrime[i];

  // primePrimePref[i] = no of prime prime no from 1 ... i
  for (int i = 1; i <= N; i++)
    primePrimePref[i] = primePrimePref[i - 1] + (isPrime[primeCnt[i]] ? 1 : 0);
}

int32_t main() {
  preprocess();

  int t;
  cin >> t;

  while (t--) {
    int l, r;
    cin >> l >> r;

    cout << primePrimePref[r] - primePrimePref[l - 1] << endl;
  }

  return 0;
}