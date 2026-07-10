#include <bits/stdc++.h>
using namespace std;

// ETF = counts the no of +ve int upto n which are co-prime to n
// phi(n)

// Brute Force : TC = O(N * LogN)
int phiNaive(int n){
  int cnt = 0;

  for(int i = 1; i <= n; i++)
    if(gcd(i,n) == 1)
      cnt++;

  return cnt;
  
}

/* 

Obsv : 

phi(2) = 1
phi(3) = 2
phi(5) = 4
phi(7) = 6
phi(11) = 10

phi(p) = p-1 where p = primeNo
phi(p^x) = No of int not co-prime with prime p 
         = p^x - (p^x)/p


- a,b must be co-prime
  phi(a * b) = phi(a) * phi(b); 


- a,b need not be co-prime
  phi(a + b) = phi(a) + phi(b) + gcd(a,b)/phi(gcd(a,b)); 


*/
