#include <bits/stdc++.h>
using namespace std;

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