class Solution {// ! TC = O(NlogK) 
    // SC = O(K) - k size heap 
      public:
        // Function to return kth largest element from an array.
        int KthLargest(vector<int> &arr, int k) {
      // we will create a minHeap of k elements
      // and compare rest of elements of arr (n-k) with top element of heap
      // if thay are greater > top most of heap replace it
      // ans = top element of heap
      
      int n = arr.size() - 1;
      // MIN HEAP
      priority_queue<int,vector<int>,greater<int>>p;
      
      for(int i = 0; i<k ; i++)
            p.push(arr[i]);
      
      
      for(int i = k ; i<= n; i++)
      {
          if(arr[i] > p.top())
          {
              p.pop();
              p.push(arr[i]);
          }
      }
      
    return p.top();  
        }
    };