//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


//! BRUTE FORCE 
class Solution { //! TC = O(NK)    // SC = O(K) -- using Q
  public:
  // function to print first -ve no
  int display(queue<int> q){
      while(!q.empty()){
          if(q.front()<0)
          return q.front();
          
          //else 
          q.pop(); 
      }
      return 0; // if there is no -ve no in window
  }
  
  
    vector<int> FirstNegativeInteger(vector<int>& arr, int k,int vector<int> ans) {
        // write code here
        
        vector<int> ans;
        queue<int> q;
        
        // first push k-1 elements in q
        for(int i = 0; i<k-1 ; i++)
        q.push(arr[i]);
        
        for(int i = k-1 ; i<n ; i++){
            // creating a sliding window
            q.push(arr[i]);// push ith element in q (back)
            ans.push_back(display(q)); // print first -ve no of window
            q.pop(); // pop (front) 
        }
        return ans;
    }
};



//! optimized TC = O(n)   - we we'll store only idx of -ve element in Q
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// OPTIMIZED 
class Solution { //! TC = O(N)    // SC = O(K) -- using Q
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        
        vector<int> ans;
        queue<int> q;
        int n = arr.size();
        
        // first push k-1 (-ve)elements ke index  in q
        for(int i =0; i<k-1; i++){
            if(arr[i]<0)
            q.push(i);
        }
        
        for(int i = k-1; i<n ; i++){
            
            // push ith -ve element ke idx
            if(arr[i]<0)
            q.push(i);
            
            
            // no _ve elements
            if(q.empty())
            ans.push_back(0);
            
            else // q is not empty
            {
                // before printing check if that -ve element ka idx belongs to window
                if(q.front() <= i-k)
                q.pop();
                
                //q is khali
                if(q.empty())
                ans.push_back(0);
                // q has elements print the first -ve element 
                else
                ans.push_back(arr[q.front()]);
                    
                
            }
        }
      return ans;
    }
};
