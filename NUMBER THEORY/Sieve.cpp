#include <bits/stdc++.h>
using namespace std;

// TC = O(N* Log(Log(N)));
class Solution {
  public:
    vector<int> sieve(int n) {
        // code here
        vector<int>isPrime(n+1,1);
        // isPrime[0] = isPrime[1] = 0;
        for(int i = 2; i*i <= n;i++)
        {
            if(isPrime[i])
            {
                for(int j = i*i; j <= n; j += i)
                {
                    isPrime[j]= 0;
                }
            }
        }
    vector<int>res;
    
    for(int i= 2; i <= n;i++)
    {
        if(isPrime[i])
        res.push_back(i);
    }
    return res;
    }
};

