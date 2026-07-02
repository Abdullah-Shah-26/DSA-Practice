#include<bits/stdc++.h>
using namespace std;

bool checkMirror(int n, vector<vector<int>> &A, vector<vector<int>> &B)
 {
     unordered_map<int, stack<int>>m;

     for(int i = 0;i < A.size(); i++)
     {
        //  m[A[i]].push(A[i+1]);
        int u = A[i][0];
        int v = A[i][1];
        m[u].push(v);
     }

     for(int i = 0;i < B.size(); i++)
     {
        //  if(m[B[i]].top() != m[B[i+1]])
        //  return 0;

        //  m[B[i]].pop();
        int u = B[i][0];
        int v = B[i][1];

        if(m[u].empty() || m[u].top() != v)
        return 0;

        m[u].pop();
     }
     return 1;
 }
 