class Solution {
    public:
      priority_queue<int>leftMaxHeap; // for smaller half
      priority_queue<int, vector<int>,greater<int>>rightMinHeap;// for larger hal
      
      // funciton to insert in heap
      void insertHeap(int &x)
      {
          if(leftMaxHeap.empty() || x <= leftMaxHeap.top())
          leftMaxHeap.push(x); // insert into max-heap
          
          else // x > leftMaxheap
          rightMinHeap.push(x); // insert in minheap
          
          // Balance the heaps
          balanceHeaps();
      }
      
      // function to balance 2 heaps
      void balanceHeaps()
      {
          
          // if size of minheap(R) > maxheap(L) 
          // right ka top element left mein daldo
          
          if(rightMinHeap.size() > leftMaxHeap.size())
          {
              leftMaxHeap.push(rightMinHeap.top());
              rightMinHeap.pop();
          }
           // difference b/w left - right size shouldn't be > 1
          else if(rightMinHeap.size() < leftMaxHeap.size() - 1)
              {
              // left ka top right mein daldo 
              rightMinHeap.push(leftMaxHeap.top());
              leftMaxHeap.pop();
                  
               }
          }
      
  
    
      vector<double> getMedian(vector<int> &arr) {
          
          vector<double>medians; // to store all medians
          for(int x : arr)
          {
              // insert curr element into heap
           insertHeap(x);
          double median;
          // if left size > right size
          if(leftMaxHeap.size() > rightMinHeap.size())
          medians.push_back(leftMaxHeap.top()); // left ka top is median 
          
          // if both heaps are equal, median is avg of their tops
          else
          medians.push_back((leftMaxHeap.top() + rightMinHeap.top())/2.0);
          
          }
            return medians;
      }
    
  };