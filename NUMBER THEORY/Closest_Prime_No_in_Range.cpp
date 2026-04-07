#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log (LogN))
//! SC = O(A)
class Solution {
public:
    vector<int> primeSieve(int n){
      vector<int> result;

      vector<int> isPrime(n + 1, 1);

      for(int i = 2; i*i <= n; i++){
        if(isPrime[i]){
          for(int j = i*i; j <= n; j+=i){
            isPrime[j] = 0;
          }
        }
      }

      for(int i = 2; i <= n; i++){
        if(isPrime[i]){
          result.push_back(i);
        }
      }

      return result;
    }

    vector<int> closestPrimes(int left, int right) {
    vector<int> primes = primeSieve(right);  
    int n = primes.size();

    vector<int> result = {-1,-1};
    
    int diff = INT_MAX;
    for(int j = 0; j < n - 1; j++){
        if(left > primes[j] || right < primes[j+1]) continue;

        int curdiff = primes[j+1] - primes[j];

        if(curdiff < diff){
          result = {primes[j], primes[j+1]};
          diff = curdiff;
        }
      
    }
    return result;
    }
};