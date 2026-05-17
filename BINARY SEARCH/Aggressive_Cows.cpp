class Solution { // TC = O(nlogn)
    public:
  // Binary search apporoach - exactly opposite of Book allocation problem 
      int aggressiveCows(vector<int> &stalls, int k) {
          int st = 1 , end , mid, ans;
          int n = stalls.size();
          // sort arr in increasing order
          sort(stalls.begin(),stalls.end());
      end = stalls[n-1] - stalls[0];
      // apply binary search on this range
      while(st <= end) // O(Logn)
      {// least allowed min distance b/w cows can be greater but not less
          mid = st + (end - st)/2;
          int count = 1, pos = stalls[0]; // assigned 1st cow to 1st stall
          for(int i = 1; i < n ; i++)// O(n)
          {
              if(pos + mid <= stalls[i])
              { // if we are able to assign cows keeping mindist then increase cows until req k 
                  count ++;
                  pos = stalls[i];
              }
          }
      if(count < k) // < no of cows        
          end = mid - 1; // unable to assign cows keeping minallowed dist then Increase the min allowed dist
      else 
      {
          ans = mid; // if able to assign // store in ans 
          //then go right to find max possible minallowed dist
          st = mid + 1;
      }
      }
      return ans;
      }
      
  };
  