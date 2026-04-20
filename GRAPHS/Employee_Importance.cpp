#include <bits/stdc++.h>
using namespace std;

//* TC = O(V + E) | SC = O(V)

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
  public:
    int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> m; // EmpId -> Employee*

    for(auto &emp : employees){
      m[emp->id] = emp;
    }

    int sum = 0;

    queue<Employee*> q;
    q.push(m[id]);
    
    while(!q.empty()){
      Employee* cur = q.front();
      q.pop();

      sum += cur->importance;

      for(auto &subId : cur->subordinates){
        q.push(m[subId]);
      }
    }

    return sum;
    }
};


//* DFS

class Solution {
  public:
    void dfs(int id, int &sum, unordered_map<int, Employee*> &m){
      
      sum += m[id]->importance;
    
      for(auto &subId : m[id]->subordinates){
        dfs(subId, sum, m);
      }
    }

    int getImportance(vector<Employee*> employees, int id) {
      unordered_map<int, Employee*> m;

      for(auto emp : employees){
        m[emp->id] = emp;
      }

      int sum = 0; 
      dfs(id, sum, m);
      return sum;
    }
};