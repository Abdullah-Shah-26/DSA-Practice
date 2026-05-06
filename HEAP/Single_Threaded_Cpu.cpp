#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef pair<int,int> P;
    vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();

    for(int i = 0; i < n; i++){
      tasks[i].push_back(i);
    }

    sort(begin(tasks), end(tasks));
 
    vector<int> ans;
    priority_queue<P, vector<P>, greater<P>> pq; // duration, idx

    long long curTime = 0;
    int idx = 0;

    while(idx < n || !pq.empty()){

      if(pq.empty() && curTime < tasks[idx][0]){
        curTime = tasks[idx][0]; // Initially curTime = 1st task st time
      }

      while(idx < n && tasks[idx][0] <= curTime){
        pq.push({tasks[idx][1], tasks[idx][2]});
        idx++;
      }

      pair<int,int> curTask = pq.top();
      pq.pop();

      curTime += curTask.first; // processing Time
      ans.push_back(curTask.second); // Idx
    }

    return ans;
    }
};