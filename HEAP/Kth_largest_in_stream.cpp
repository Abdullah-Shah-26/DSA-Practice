class Solution {
    public: // TC = O(nlogk) // SC = O(k) - k size min heap 
      vector<int> kthLargest(int k, int arr[], int n) {
      vector<int> ans; 
  // for k-1 elemets we cant find the kth largest so ans = -1
      for(int i = 0 ; i < k-1; i++)
      {
          ans.push_back(-1);
      }
  // we'll use similar logic of kth largest element 
  // create a prioriy q - that is --MIN HEAP of k elements and compare the rest of elements ( k to n -1) in a loop 
  // with pq top if its less well replace it with the new element of stream
      priority_queue<int,vector<int>,greater<int>>pq;
      // first insert k elemmens in pq 
      for(int i = 0 ; i < k; i++)
      {
       pq.push(arr[i]);   
      }
      ans.push_back(pq.top());
      
      for(int i = k; i < n ; i++)
      {
          if(pq.top() < arr[i])
          {
              pq.pop();
              pq.push(arr[i]);
          }
          ans.push_back(pq.top());
      }
     
     return ans;
  }
  };