class Solution {
    public:
      int findMin(vector<int>& arr) {
          // complete the function here
          
          // binary search approach
          // tc = Ologn
          
          int st = 0 , end = arr.size()-1, ans = arr[0];// to handle edge case 
          // where array is not rotated
          
          while(st <= end)
          {
              int mid = st + (end - st)/2;
              
          // left side sorted go right to find min
              if(arr[mid] >= arr[0])
              st = mid + 1; 
              else
              { // right side sorted go left to find min but before going store potential ans 
                  ans = arr[mid];
                  end = mid - 1;
              }
          }
          return ans;
      }
  };