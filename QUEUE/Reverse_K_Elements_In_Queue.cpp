//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
public:
  // Function to reverse first k elements of a queue.
  queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;

    for (int i = 0; i < k; i++) {
      s.push(q.front());
      q.pop();
    }

    int n = q.size();

    while (!s.empty()) {
      q.push(s.top());
      s.pop();
    }

    for (int i = 0; i < n; i++) {
      q.push(q.front());
      q.pop();
    }

    return q;
  }
};