//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        // push first k elements of Q in stack
        for(int i = 0; i<k ; i++){
            s.push(q.front());
            q.pop();
        }
        // store the remaining size of Q 
        int n = q.size();
        // push all stack elements into Q 
        // they are reversed as they are poped out of stack
    while(!s.empty()){
    q.push(s.top());
    s.pop();
    }
    // push the first n elements of Q at last 
    for(int i = 0 ; i<n ; i++){
        q.push(q.front());// push elements at back then remove them form fornt
        q.pop();
    }
    
    return q;
    }
};