#include <bits/stdc++.h>
using namespace std;

//! interview Bit
int Solution::nchoc(int A, vector<int> &B) {
    
    // Max Heap 
    priority_queue<int>p;
  
     // push all the elements in priority_queue
    for(int i = 0; i < B.size(); i++)
    p.push(B[i]);
     
     
     long long MaxChoc = 0;
     // until A and Pq isnt empty remove top element and add in total chococates eaten
     // and push half of it back into Q until given time becomes A =+- 0
     while(A &&  !p.empty())
     {
         MaxChoc += p.top();
         
         if(p.top()/2) //its useless to push 0
         p.push(p.top()/2);
         
         p.pop();
         A--;
     }
     return MaxChoc% 1000000007; // to avoid int overflow
     
     
  }
 