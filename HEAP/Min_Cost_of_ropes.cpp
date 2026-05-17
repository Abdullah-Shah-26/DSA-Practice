class Solution {
    public:
      int minCost(vector<int>& arr) {
      int n = arr.size();
      // first push all the elements in priority q - min heap
      // we will pop 2 elements from p and add them to find cost and push that sum of lenght
      // back in q 
      priority_queue<int, vector<int>,greater<int>>p;
      for(int i = 0; i< n;i++)
          p.push(arr[i]);
          
          
          int cost = 0;
      
          while(p.size() > 1)
          {
              int rope = p.top();
              p.pop();
              rope += p.top();
              p.pop();  
              cost += rope;
              p.push(rope);
          }
        
        
          return cost;
      }
  };