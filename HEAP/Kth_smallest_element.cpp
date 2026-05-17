class Solution { // TC = O(nlogk)
    public:
      // arr : given array
      // k : find kth smallest element and return using this function
      int kthSmallest(vector<int> &arr, int k) {
          // we will create MAX heap of k elements and compare the largest element of heap to remaining elements (n-k)
          // with top most element of heap if its smaller then replace it with top most element 
          // and the final ans = top element of heap ( kth smallest)
          
          int n = arr.size()-1;
          priority_queue<int>p; // Max heap
          
          for(int i = 0; i < k ; i++)
              p.push(arr[i]);
              
          for(int i = k; i <= n ; i++)
          {
              if(arr[i] < p.top())
              {
                  p.pop();
                  p.push(arr[i]);
              }
          }
          return p.top();
      }
  };